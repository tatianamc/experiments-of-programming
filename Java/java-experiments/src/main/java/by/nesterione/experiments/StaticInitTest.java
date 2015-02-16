package by.nesterione.experiments;

public class StaticInitTest {
	
	//Static initialization will be when object Class will load first time 
	//
	//First will initialization static members outside static section
	//Second will initialization static member inside static section
	//Last all other members
	public static void main(String[] args) {
		
		System.out.println("Init reference:");
		StaticClass c;
		System.out.println("Create object:");
		//This point of initialization static members
		c = new StaticClass();
		
		//or when will use static member
		//StaticClass.notifier1 = null;
		
	}
}


class StaticClass {
	public static Notifier notifier2;
	public static Notifier notifier1 = new Notifier(1);
	public Notifier notifier3;
	public static int static_num = 0;
	public int num = 0;
	
	
	static {
		notifier2 = new Notifier(2);
	}
	
	public StaticClass() {
		notifier3 = new Notifier(3);
	}
}