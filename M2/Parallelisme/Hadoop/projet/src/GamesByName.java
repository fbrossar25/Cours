import java.io.IOException;
import java.lang.InterruptedException;
import java.lang.StringBuilder;
import java.util.Iterator;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * MapReduce (Name) -> (Platform, Global_Sales, Critic_Scores), formattage:<br>
 * Name\t
 * Platform1,Global_Sales1,Critic_Scores1;Platform2,Global_Sales2,Critic_Scores2
 */
public class GamesByName {
    public static class GamesByNameMapper extends Mapper<Object, Text, Text, Text> {
        boolean headerSkipped = false;

        public boolean checkAllNotNullOrEmpty(String... fields) {
            for (String f : fields) {
                if (f.trim().isEmpty()) {
                    return false;
                }
            }
            return true;
        }

        public boolean checkFields(String[] fields) {
            return fields.length == 16 && checkAllNotNullOrEmpty(fields[0], fields[1], fields[9], fields[10]);
        }

        public void map(Object key, Text value, Context context) {
            if (!headerSkipped) {
                headerSkipped = true;
                return;
            }
            // -1 car on garde les champs vide
            String[] fields = value.toString().split(",", -1);
            if (!checkFields(fields)) {
                return;
            }
            StringBuilder valueBuilder = new StringBuilder();
            String name = fields[0].trim();// clé
            valueBuilder.append(fields[1].trim()).append(",");// platform
            valueBuilder.append(fields[9].trim()).append(",");// global_sales
            valueBuilder.append(fields[10].trim());// critic_score
            try {
                context.write(new Text(name), new Text(valueBuilder.toString()));
            } catch (IOException | InterruptedException e) {
                System.err.println(e.getMessage());
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }

    public static class GamesByNameReducer extends Reducer<Text, Text, Text, Text> {
        public void reduce(Text key, Iterable<Text> values, Context context) {
            StringBuilder resultBuilder = new StringBuilder();
            Iterator<Text> it = values.iterator();
            while (it.hasNext()) {
                Text value = it.next();
                resultBuilder.append(value);
                if (it.hasNext()) {
                    resultBuilder.append(";");
                }
            }
            try {
                context.write(key, new Text(resultBuilder.toString()));
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }
}