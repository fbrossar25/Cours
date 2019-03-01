import java.io.IOException;
import java.lang.InterruptedException;
import java.lang.StringBuilder;
import java.util.Arrays;
import java.util.Iterator;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.BooleanWritable;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * MapReduce (Name, Platform) -> (Influenced), formattage:<br>
 * Name|Platform Influenced<br>
 * Influenced = Oui|Non
 */
public class GamesInfluenced {

    public static boolean isInfluenced(Double ratio, String platform) {
        Double temoin = Projet.ratioTemoins.get(platform);
        if (temoin == null) {
            System.err.println("Pas de témoin pour la plateforme : " + platform);
            System.exit(-1);
        }
        return ratio >= (0.8 * temoin) && ratio <= (1.2 * temoin);
    }

    public static class GamesInfluencedMapper extends Mapper<Object, Text, Text, BooleanWritable> {
        public void map(Object key, Text value, Context context) {
            String[] fields = value.toString().split("\t");
            String keyValue = fields[0];
            String platform = keyValue.split("\\|")[1];
            Double ratio = Double.parseDouble(fields[1]);
            try {
                context.write(new Text(keyValue), new BooleanWritable(isInfluenced(ratio, platform)));
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }

    public static class GamesInfluencedReducer extends Reducer<Text, Text, Text, BooleanWritable> {
        public void reduce(Text key, Iterable<BooleanWritable> values, Context context) {
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