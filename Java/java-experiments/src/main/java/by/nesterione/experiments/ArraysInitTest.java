package by.nesterione.experiments;

public class ArraysInitTest {
	public static void main(String[] args) {
		int[] a1 = new int[5];
		int[] a2 = {1,2,3,4,5};
		int[] a3 = new int[] {1,2,3};
		Integer[] a4 = new Integer[5];
		Integer[] a5 = {1,2,3,4,5}; //Auto boxing
		Integer[] a6 = {new Integer(3), new Integer(2)};
		Integer[] a7 = new Integer[] {new Integer(5), new Integer(1)};
		
		printArray(a1);
		printArray(a2);
		printArray(a3);
		printArray(a4);
		printArray(a5);
		printArray(a6);
		printArray(a7);
	}
	
	public static void printArray(Integer[] array) {
		System.out.print("Array: ");
		for(Integer val : array ) {
			System.out.print(val + " ");
		}
		System.out.println();
	}
	
	public static void printArray(int[] array) {
		System.out.print("Array: ");
		for(int val : array ) {
			System.out.print(val + " ");
		}
		System.out.println();
	}
}
