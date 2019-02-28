
/**
 * Matrix Multiplication.
 * Consider matrices A (L,M)   (L lines, M cols) 
 *               and B (M,N)   (M lines, N cols)   
 * we want to compute resulting matrix 
 *                   A x B = C (L,N)
 *
 * The input should be in a text file formatted as:
 * A : [0 1 2 3 4] [5 6 7 8 9]
 * B : [0 1 2] [3 4 5] [6 7 8] [9 10 11] [12 13 14]
 *
 * Stéphane Genaud, Nov 2013
 **/

import java.io.IOException;

import java.util.List;
import java.util.ArrayList;
import java.lang.StringBuilder;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class Dijkstra {

	public static class Map extends Mapper<LongWritable, Text, Text, Text> {

		/**
		 * map : the map function implementation
		 *
		 * @param key
		 * @param value  the data from input files, one line per map invocation
		 * @param contex a place to write the (key,value) pairs we want to emit
		 **/
		public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
			String[] arrete = value.toString().replace("(", "").replace(")", "").split(",");
			context.write(new Text(arrete[0]), value);
			context.write(new Text(arrete[1]), value);
		}
	}

	public static class Reduce extends Reducer<Text, Text, Text, Text> {

		/**
		 * reduce
		 * 
		 * @param key     the key as Text
		 * @param values  the list of values associated to key
		 * @param context the place to store outputs (goes to results)
		 **/

		public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
			Integer result = 0;
			List<Text> valuesList = new ArrayList<>();
			for (Text value : values) {
				valuesList.add(new Text(value.toString()));
				result++;
			}
			for (Text value : valuesList) {
				context.write(new Text(value), new Text("d(" + key + ")=" + result));
			}
		}
	}

	public static class Identity extends Mapper<LongWritable, Text, Text, Text> {

		public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
			String[] arrete = value.toString().split("\t");
			context.write(new Text(arrete[0]), new Text(arrete[1]));
		}
	}

	public static class ReduceStep2 extends Reducer<Text, Text, Text, Text> {
		public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
			StringBuilder sb = new StringBuilder();
			sb.append("\t");
			for (Text value : values) {
				sb.append(value).append("\t");
			}
			context.write(key, new Text(sb.toString()));
		}
	}

	public static void main(String[] args) throws Exception {

		if (args.length < 2) {
			System.err.println("Usage : hadoop jar Dijkstra.jar Dijkstra dijkstra.in res.out");
			System.exit(0);
		}

		Configuration conf = new Configuration();

		Job job = new Job(conf, "Dijkstra");
		job.setJarByClass(Dijkstra.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);

		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));

		job.waitForCompletion(true);

		Job job2 = new Job(conf, "Dijkstra Step2");
		job2.setJarByClass(Dijkstra.class);
		job2.setOutputKeyClass(Text.class);
		job2.setOutputValueClass(Text.class);

		job2.setMapperClass(Identity.class);
		job2.setReducerClass(ReduceStep2.class);

		job2.setInputFormatClass(TextInputFormat.class);
		job2.setOutputFormatClass(TextOutputFormat.class);

		FileOutputFormat.setOutputPath(job2, new Path(args[1] + ".final"));
		FileInputFormat.addInputPath(job2, new Path(args[1] + "/part-r-00000"));

		job2.waitForCompletion(true);
	}
}
