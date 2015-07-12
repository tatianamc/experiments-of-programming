public class TestJNI {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("start");
		TestJNI ex = new TestJNI();
		System.out.println("before");
		int result = ex.tn();
		System.out.println("After native method call.");
		System.out.println("Result = " + result);
	}

	public native int tn();

	static {
		System.out.println("D L");
		System.load("D:/TestJNI.dll");
	}
}
