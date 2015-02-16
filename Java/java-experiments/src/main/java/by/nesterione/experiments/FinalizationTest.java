package by.nesterione.experiments;

public class FinalizationTest {
	public static void main(String[] args) {
		Book novel = new Book(true);
		novel.checkIn();
		novel = null;
		System.gc();
		new Book(true);
		System.gc();
		
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class Book {
	boolean checkedOut = false;
	
	Book(boolean checkOut) {
		checkedOut = checkOut;
	}
	
	void checkIn() {
		checkedOut = false;
	}
	
	public void finalize() {
		System.out.println("Вызов finalize");
		if(checkedOut) {
			System.out.println("Ошибка. checedOut");
		}
	}
}