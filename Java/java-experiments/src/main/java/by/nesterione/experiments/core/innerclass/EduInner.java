package by.nesterione.experiments.core.innerclass;

public class EduInner {
	
	public static void main(String[] args) {
		DoNew dn = new DoNew();
		DoNew.Inner dni = dn.new Inner();
	}
	
}

class DoNew {
	public class Inner {};
}

class DoThis {
	
	void f() {System.out.println("DotThis.f()");};
	
	public class Inner {
		public DoThis outer() {
			return DoThis.this;
		}
	}
	
	public Inner inner() {return new Inner();}
}