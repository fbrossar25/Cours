import java.io.IOException;
import java.lang.InterruptedException;
import java.lang.StringBuilder;
import java.util.Arrays;
import java.util.Iterator;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * MapReduce (Name, Platform) -> (Ratio), formattage:<br>
 * Name|Platform Ratio
 */
public class GamesRatio {
    public static class GamesRatioMapper extends Mapper<Object, Text, Text, DoubleWritable> {
        public void map(Object key, Text value, Context context) {
            String[] fields = value.toString().split("\t");
            String keyValue = fields[0];
            String platform = keyValue.split("\\|")[1];
            String[] gameFields = fields[1].split(",");
            Double ratio = 100.0 * (Double.parseDouble(gameFields[0]) / Integer.parseInt(gameFields[1]));
            if (!Projet.ratioTemoins.containsKey(platform)) {
                Projet.ratioTemoins.put(platform, ratio);
            }
            try {
                context.write(new Text(keyValue), new DoubleWritable(ratio));
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }

    public static class GamesRatioReducer extends Reducer<Text, Text, Text, DoubleWritable> {
        public void reduce(Text key, Iterable<DoubleWritable> values, Context context) {
            try {
                // Il n'y as pas deux jeux de même nom sur une même plateforme
                context.write(key, values.iterator().next());
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }
}