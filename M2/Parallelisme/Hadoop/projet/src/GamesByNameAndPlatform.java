import java.io.IOException;
import java.lang.InterruptedException;
import java.lang.StringBuilder;
import java.util.Iterator;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * MapReduce (Name, Platform) -> (Global_Sales, Critic_Scores), formattage:<br>
 * Name|Platform Platform,Global_Sales,Critic_Scores
 */
public class GamesByNameAndPlatform {
    public static class GamesByNameAndPlatformMapper extends Mapper<Object, Text, Text, Text> {
        public void map(Object key, Text value, Context context) {
            String[] fields = value.toString().split("\t");
            String name = fields[0];
            String[] games = fields[1].split(";");
            for (String game : games) {
                String[] game_fields = game.split(",");
                StringBuilder valueBuilder = new StringBuilder();
                valueBuilder.append(game_fields[1]).append(",");
                valueBuilder.append(game_fields[2]);
                try {
                    context.write(new Text(name + "|" + game_fields[0]), new Text(valueBuilder.toString()));
                } catch (IOException | InterruptedException e) {
                    System.err.println(e.getMessage());
                    e.printStackTrace();
                    System.exit(-1);
                }
            }
        }
    }

    public static class GamesByNameAndPlatformReducer extends Reducer<Text, Text, Text, Text> {
        public void reduce(Text key, Iterable<Text> values, Context context) {
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