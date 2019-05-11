

import java.io.IOException;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class WordCount {

  public static class TokenizerMapper 
       extends Mapper<Object, Text, Text, IntWritable>{
  
    private Text gare = new Text();
    private final int CHAMP_GARE = 4;
    private final int CHAMP_DATE = 0;
    private boolean headerSkipped = false;
      
    public void map(Object key, Text value, Context context
                    ) throws IOException, InterruptedException {
      if(!headerSkipped){
        headerSkipped = true;
        return;
      }
      String[] champs = value.toString().split(";");
      if(champs.length != 6
        || "".equals(champs[CHAMP_DATE])
        || "".equals(champs[CHAMP_GARE]))
        return;
      int mois = 0;
      try{
        gare.set(champs[CHAMP_GARE]);
        mois = Integer.parseInt(champs[CHAMP_DATE].substring(5,7));
        context.write(gare, new IntWritable(mois));
      }catch(Exception e){
        System.err.println(e.getMessage());
        e.printStackTrace(System.err);
        System.err.println("gare : '"+champs[CHAMP_GARE]+"', date : '"+champs[CHAMP_DATE]+"'");
      }
      
    }
  }
  
  public static class IntSumReducer 
       extends Reducer<Text,IntWritable,Text,Text> {
    private Text result = new Text();
    
    public void reduce(Text key, Iterable<IntWritable> values, 
                       Context context
                       ) throws IOException, InterruptedException {
      int[] compteurs = {0,0,0,0,0,0,0,0,0,0,0,0};
      for(IntWritable i : values){
        compteurs[i.get()-1]++;
      }
      int max_idx = 0;
      StringBuilder result_builder = new StringBuilder(32);
      result_builder.append(": ");
      result_builder.append(compteurs[0]).append(" ");
      for(int i=1; i<12; i++){
        if(compteurs[i] > compteurs[max_idx]){
          max_idx = i;
        }
        result_builder.append(compteurs[i]).append(" ");
      }
      result_builder.append("(").append(max_idx+1).append(")");
      result.set(result_builder.toString());
      context.write(key, result);
    }
  }

  public static class TokenizerMapperGare 
       extends Mapper<Object, Text, IntWritable, Text>{
  
    private Text gare = new Text();
      
    public void map(Object key, Text value, Context context
                    ) throws IOException, InterruptedException {
      String[] champs = value.toString().split(":");
      if(champs.length != 2)
        return;
      int mois = 0;
      try{
        gare.set(champs[0].trim());
        mois = Integer.parseInt(champs[1].split("\\(")[1].replaceAll("\\)",""));
        System.out.println("Mois = "+mois);
        context.write(new IntWritable(mois), gare);
      }catch(Exception e){
        System.err.println(e.getMessage());
        e.printStackTrace(System.err);
        System.err.println("gare : '"+champs[0]+"', mois : '"+champs[1]+"'");
      }
    }
  }
  
  public static class IntSumReducerGare 
       extends Reducer<IntWritable,Text,IntWritable,Text> {
    private Text result = new Text();
    
    public void reduce(IntWritable key, Iterable<Text> values, 
                       Context context
                       ) throws IOException, InterruptedException {
      StringBuilder result_builder = new StringBuilder(512);
      result_builder.append("(").append(key).append(") ");
      for(Text gare : values){
        result_builder.append(gare).append("   ");
      }
      result.set(result_builder.toString());
      context.write(key, result);
    }
  }

  public static void main(String[] args) throws Exception {
    Configuration conf = new Configuration();
    String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();
    FileSystem fs = FileSystem.newInstance(conf);

    if (otherArgs.length != 2) {
      System.err.println("Usage: wordcount <in> <out>");
      System.exit(2);
    }
    Job job = new Job(conf, "word count");
    job.setJarByClass(WordCount.class);
    job.setMapperClass(TokenizerMapper.class);
    job.setReducerClass(IntSumReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
    FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
    FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
    if(job.waitForCompletion(true)){
      System.out.println("job 1 complete");
    }else{
      System.err.println("job 1 incomplete");
      System.exit(-1);
    }

    Job job2 = new Job(conf, "gare count");
    job2.setJarByClass(WordCount.class);
    job2.setMapperClass(TokenizerMapperGare.class);
    job2.setReducerClass(IntSumReducerGare.class);
    job2.setOutputKeyClass(IntWritable.class);
    job2.setOutputValueClass(Text.class);
    FileInputFormat.addInputPath(job2, new Path(otherArgs[1]+"/part-r-00000"));
    FileOutputFormat.setOutputPath(job2, new Path(otherArgs[1]+"-final"));
    System.exit(job2.waitForCompletion(true) ? 0 : 1);
  }
}
