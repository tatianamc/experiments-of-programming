package by.nesterione.experiments.core.concurents.forkfr;

import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class ExampleRecursiveTask {

	public static void main(String[] args) {
		ForkJoinPool fjp = new ForkJoinPool();
		double[] nums = new double[5000];
		
		for (int i = 0; i < nums.length; i++) {
			nums[i] = ((i%2)==0)?i:-i;
		}
		
		Sum task = new Sum(nums, 0, nums.length);
		
		//double summ = fjp.invoke(task);
		fjp.execute(task);
		
		while(!task.isDone()) {
			System.out.println(fjp);
		}
		
		System.out.println("Summation: "+ fjp.invoke(task));
	}
}

class Sum extends RecursiveTask<Double> {
	final int seq = 500;
	double[] data;
	int start, end;
	
	Sum(double[] data, int s, int e) {
		this.data = data;
		this.start = s;
		this.end = e;
	}
	
	@Override
	protected Double compute() {
		System.out.println("__RUni");
		double sum = 0;
		if((end-start)<seq) {
			for(int i = start; i<end; i++) sum+=data[i];
		} else {
			int middle = (start + end) /2;
			Sum subTaskA = new Sum(data, start, middle);
			Sum subTaskB = new Sum(data, middle, end);
			
			subTaskA.fork();
			subTaskB.fork();
			
			//Подождать завершения задачи и сложить результат
			sum = subTaskA.join() + subTaskB.join();
		}
		return sum;
	}
}