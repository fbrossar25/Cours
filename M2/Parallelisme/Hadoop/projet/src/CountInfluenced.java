import java.io.IOException;
import java.lang.InterruptedException;
import java.lang.StringBuilder;
import java.util.Arrays;
import java.util.Iterator;
import java.util.stream.StreamSupport;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.BooleanWritable;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * MapReduce (Oui|Non) -> (Nombre,Pourcentage)
 */
public class CountInfluenced {
    private static Long numberOfEntries = 0L;

    public static class CountInfluencedMapper extends Mapper<Object, Text, Text, Text> {
        public void map(Object key, Text value, Context context) {
            numberOfEntries++;
            String[] fields = value.toString().split("\t");
            Boolean influenced = Boolean.parseBoolean(fields[1]);
            try {
                context.write(new Text(influenced ? "Oui" : "Non"), new Text(fields[0]));
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }

    public static class CountInfluencedReducer extends Reducer<Text, Text, Text, Text> {
        public void reduce(Text key, Iterable<Text> values, Context context) {
            try {
                long valuesCount = StreamSupport.stream(values.spliterator(), false).count();
                double pourcentage = ((1.0 * valuesCount / numberOfEntries) * 100.0);
                double arrondis = Math.round(pourcentage * 100.0) / 100.0;
                // Il n'y as pas deux jeux de même nom sur une même plateforme
                context.write(key, new Text(valuesCount + " " + arrondis));
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }
}