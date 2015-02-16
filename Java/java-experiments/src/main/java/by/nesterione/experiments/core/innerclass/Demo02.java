package by.nesterione.experiments.core.innerclass;

public class Demo02 {

	static void takesD(D d) {}
	static void takesE(E e) {}
	
	public static void main(String[] args) {
		Z z = new Z();
		takesD(z);
		takesE(z.makeE());
	}
}

class D {}
abstract class E {}

class Z extends D {
	E makeE() {return new E() {}; }
}