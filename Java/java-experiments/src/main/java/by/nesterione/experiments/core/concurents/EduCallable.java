package by.nesterione.experiments.core.concurents;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class EduCallable {
	public static void main(String[] args) {
		ExecutorService es = Executors.newFixedThreadPool(3);
		Future<Integer> f1;
		Future<Double> f2;
		Future<Integer> f3;
		
		f1 = es.submit(new Sum(10));
		f2 = es.submit(new Hypot(4, 5));
		f3 = es.submit(new Factorial(5));
		
		try {
			System.out.println("calc values:");
			System.out.println(f1.get());
			System.out.println(f2.get());
			System.out.println(f3.get());
		} catch (InterruptedException ex) { System.out.println("ex");}
		catch (ExecutionException ex) {
			 System.out.println("exec ex");
		}
		
		es.shutdown();
	}
}

//Three threads 
class Sum implements Callable<Integer>  {
	int stop;
	
	public Sum(int stop) {this.stop = stop;}
	

	@Override
	public Integer call() throws Exception {
		int sum = 0;
		for(int i = 1; i <= stop; i++) {
			sum +=i;
		}
		return sum;
	}
}

class Hypot implements Callable<Double> {
	double side1, side2;
	
	Hypot(double s1, double s2) {
		side1 = s1;
		side2 = s2;
	}
	
	@Override
	public Double call() throws Exception {
		return Math.sqrt((side1*side1+ side2*side2));
	}
}

class Factorial implements Callable<Integer> {
	int stop;
	public Factorial(int stop) {this.stop = stop;}
	
	@Override
	public Integer call() throws Exception {
		int fact = 1;
		for(int i = 2; i<=stop; i++) {
			fact *=i;
		}
		return fact;
	}
}