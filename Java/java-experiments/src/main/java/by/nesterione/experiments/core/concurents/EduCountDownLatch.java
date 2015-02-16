package by.nesterione.experiments.core.concurents;

import java.util.concurrent.CountDownLatch;

public class EduCountDownLatch {
	
	
	public static void main(String[] args) {
		CountDownLatch latch = new CountDownLatch(5);
		System.out.println("run");
		new MyTh(latch);
		
		try {
			latch.await();
		} catch (InterruptedException e) {
			System.err.print(e);
		}
		System.out.println("Latch is open!");
		
	}
}

class MyTh implements  Runnable {
	
	CountDownLatch latch;
	
	public MyTh(CountDownLatch latch) {
		this.latch = latch;
		new Thread(this).start();
	}
	
	public void run() {
		for(int i = 0; i < 5; i++) {
			System.out.println(i);
			latch.countDown();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
