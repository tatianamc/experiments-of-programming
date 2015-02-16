package by.nesterione.experiments.effective;

import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class Item4CreatingDublicateObj {
	
	public static void main(String[] args) {
		
		//BAD TEST
		BadExample p1 = new BadExample(new Date());
		long startTime = System.currentTimeMillis();
		for(int i =0; i< 1000000;i++) {
			p1.isBabyBoomer();
		}
		long endTime = System.currentTimeMillis();
		long time = endTime - startTime;
		System.out.println("Bad : " + time);
		
		//IMPRUVED TEST
		impruvedExample p2 = new impruvedExample(new Date());
		startTime = System.currentTimeMillis();
		for(int i =0; i< 1000000;i++) {
			p2.isBabyBoomer();
		}
		endTime = System.currentTimeMillis();
		time = endTime - startTime;
		System.out.println("Impr : " + time);
		
		//TEST STRING CREATING (TESTED: HASN'T SPEED IMPRUVMENT)
		System.out.println("Testing string creating");
		startTime = System.currentTimeMillis();
		for(int i =0; i< 1000000000;i++) {
			String s = new String("Hello");
		}
		endTime = System.currentTimeMillis();
		System.out.println("Constructor : " + time);
		
		startTime = System.currentTimeMillis();
		for(int i =0; i< 1000000000;i++) {
			String s = "Hello";
		}
		endTime = System.currentTimeMillis();
		System.out.println("No constructor : " + time);
	}
}

class BadExample {
	private final Date birthDate;
	
	public BadExample(Date birthDate) {
		this.birthDate = birthDate;
	}
	
	//DON'T DO THIS
	public boolean isBabyBoomer() {
		Calendar gmtCal = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
		gmtCal.set(1946, Calendar.JANUARY, 1, 0, 0, 0);
		Date boomStart = gmtCal.getTime();
		gmtCal.set(1965, Calendar.JANUARY, 1, 0, 0, 0);
		Date boomEnd = gmtCal.getTime();
		return birthDate.compareTo(boomStart) >=0 && birthDate.compareTo(boomEnd) < 0;
	}
}

class impruvedExample {
private final Date birthDate;
	
	public impruvedExample(Date birthDate) {
		this.birthDate = birthDate;
	}
	
	/**
	 * The starting and ending dated of the baby boom.
	 */
	private static final Date BOOM_START;
	private static final Date BOOM_END;
	
	static {
		Calendar gmtCal = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
		gmtCal.set(1946, Calendar.JANUARY, 1, 0, 0, 0);
		BOOM_START = gmtCal.getTime();
		gmtCal.set(1965, Calendar.JANUARY, 1, 0, 0, 0);
		BOOM_END = gmtCal.getTime();
	}
	
	//DON'T DO THIS
	public boolean isBabyBoomer() {
		
		return birthDate.compareTo(BOOM_START) >=0 && birthDate.compareTo(BOOM_END) < 0;
	}
}