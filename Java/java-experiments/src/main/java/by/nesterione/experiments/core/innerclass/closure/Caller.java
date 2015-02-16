package by.nesterione.experiments.core.innerclass.closure;

public class Caller {
	private Incrementable callbackReference;
	Caller(Incrementable inc) {
		callbackReference = inc;
	}
	
	void go() {
		callbackReference.increment();
	}
}


