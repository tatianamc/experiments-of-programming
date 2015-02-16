package by.nesterione.experiments;

//Order of non static initialization
//
// At first: when field defined
// At second: In initialization section
// At last: In constructor
public class InitializationTest {
	public static void main(String[] args) {
		TestClass tc = new TestClass();
	}
}

class TestClass {
	public Notifier notifier1 = new Notifier(1);
	public Notifier notifier2;
	public Notifier notifier3;
	
	//Init section
	{
		notifier2 = new Notifier(2);
	}
	
	public TestClass() {
		notifier3 = new Notifier(3);
	}
}
