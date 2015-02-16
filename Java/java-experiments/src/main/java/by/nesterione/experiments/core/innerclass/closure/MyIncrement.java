package by.nesterione.experiments.core.innerclass.closure;

public class MyIncrement {
	protected void increment() {
		System.out.println("Other operation");
	}
	public static void f(MyIncrement mi) {mi.increment();}
 }
