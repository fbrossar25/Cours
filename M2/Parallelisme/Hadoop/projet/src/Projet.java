import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.io.Text;

public class Projet {

  public static void gamesByName(String[] args) {
    try {
      Configuration conf = new Configuration();
      Job job = new Job(conf, "GamesByName");
      job.setJarByClass(GamesByName.class);
      job.setMapperClass(GamesByName.GamesByNameMapper.class);
      job.setReducerClass(GamesByName.GamesByNameReducer.class);
      job.setInputFormatClass(TextInputFormat.class);
      job.setOutputFormatClass(TextOutputFormat.class);
      job.setOutputKeyClass(Text.class);
      job.setOutputValueClass(Text.class);
      FileInputFormat.setInputPaths(job, new Path(args[0]));
      FileOutputFormat.setOutputPath(job, new Path(args[1]));
      job.waitForCompletion(true);
    } catch (IOException | InterruptedException | ClassNotFoundException e) {
      e.printStackTrace();
      System.exit(-1);
    }
  }

  public static void main(String[] args) {
    if (args.length != 2) {
      System.err.println("Usage : hadoop jar Projet.jar Projet INPUT OUTPUT");
      System.exit(-1);
    }
    gamesByName(args);
  }
}
