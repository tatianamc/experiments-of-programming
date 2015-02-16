package by.nesterione.experiments.core.innerclass.closure;

public class Callee extends MyIncrement{
	private int i = 0;
	
	protected void increment() {
		super.increment();
		i++;
		System.out.println(i);
	}
	
	private class Closure implements Incrementable {
		private int i = 0;
		@Override
		public void increment() {
			Callee.this.increment();
		}
	}
	
	Incrementable getCallbackReference() {
		return new Closure();
	}
	
}
