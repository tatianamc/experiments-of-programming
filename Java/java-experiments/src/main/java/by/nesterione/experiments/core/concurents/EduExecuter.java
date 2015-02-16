package by.nesterione.experiments.core.concurents;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class EduExecuter {

	public static void main(String[] args) {
		CountDownLatch cdl1 = new CountDownLatch(5);
		CountDownLatch cdl2 = new CountDownLatch(5);
		CountDownLatch cdl3 = new CountDownLatch(5);
		CountDownLatch cdl4 = new CountDownLatch(5);
		ExecutorService exService = Executors.newFixedThreadPool(2);
		
		exService.execute(new MThread(cdl1, "A"));
		exService.execute(new MThread(cdl2, "B"));
		exService.execute(new MThread(cdl3, "C"));
		exService.execute(new MThread(cdl4, "D"));
		
		try {
			cdl1.await();
			cdl2.await();
			cdl3.await();
			cdl4.await();
		} catch (InterruptedException ex) {
			System.out.println("EX");
		}
	
		exService.shutdown();
	}
}

class MThread implements Runnable {

	String name;
	CountDownLatch latch;
	
	public MThread(CountDownLatch latch, String name) {
		this.latch = latch;
		this.name = name;
		new Thread(this);
	}
	
	@Override
	public void run() {
		for(int i = 0 ; i< 5; i++) {
			System.out.println( name+" : "+ i);
			latch.countDown();
		}
	}
}