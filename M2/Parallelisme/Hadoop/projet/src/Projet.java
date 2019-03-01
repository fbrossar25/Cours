import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.DoubleWritable;

import java.util.HashMap;

public class Projet {

  public static HashMap<String, Double> ratioTemoin = new HashMap<>();

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

  public static void gamesByNameAndPlatform(String[] args) {
    try {
      Configuration conf = new Configuration();
      Job job = new Job(conf, "GamesByNameAndPlatform");
      job.setJarByClass(GamesByNameAndPlatform.class);
      job.setMapperClass(GamesByNameAndPlatform.GamesByNameAndPlatformMapper.class);
      job.setReducerClass(GamesByNameAndPlatform.GamesByNameAndPlatformReducer.class);
      job.setInputFormatClass(TextInputFormat.class);
      job.setOutputFormatClass(TextOutputFormat.class);
      job.setOutputKeyClass(Text.class);
      job.setOutputValueClass(Text.class);
      FileInputFormat.setInputPaths(job, new Path(args[1]).suffix("/part-r-00000"));
      FileOutputFormat.setOutputPath(job, new Path(args[1]).suffix("/step2"));
      job.waitForCompletion(true);
    } catch (IOException | InterruptedException | ClassNotFoundException e) {
      e.printStackTrace();
      System.exit(-1);
    }
  }

  public static void gamesRatio(String[] args) {
    try {
      Configuration conf = new Configuration();
      Job job = new Job(conf, "gamesRatio");
      job.setJarByClass(GamesRatio.class);
      job.setMapperClass(GamesRatio.GamesRatioMapper.class);
      job.setReducerClass(GamesRatio.GamesRatioReducer.class);
      job.setInputFormatClass(TextInputFormat.class);
      job.setOutputFormatClass(TextOutputFormat.class);
      job.setOutputKeyClass(Text.class);
      job.setOutputValueClass(DoubleWritable.class);
      FileInputFormat.setInputPaths(job, new Path(args[1]).suffix("/step2/part-r-00000"));
      FileOutputFormat.setOutputPath(job, new Path(args[1]).suffix("/step3"));
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
    gamesByNameAndPlatform(args);
    gamesRatio(args);
  }
}
