package by.nesterione.experiments.core.innerclass.closure;

public class Main {
	
	public static void main(String[] args) {
		Callee c = new Callee();
		MyIncrement.f(c);
		
		//closure
		Caller caller = new Caller(c.getCallbackReference());
		caller.go();
		caller.go();
	}
}
