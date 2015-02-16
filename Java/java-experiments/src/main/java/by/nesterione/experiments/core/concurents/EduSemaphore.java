package by.nesterione.experiments.core.concurents;

import java.util.concurrent.*;

public class EduSemaphore {
	static class Resource {
		static public int counter;
	}

	static class ThredIm implements Runnable {

		final private String name;
	 private Semaphore sem;
		final private boolean f;

		
		public ThredIm(Semaphore sem, String name, boolean f) {
			this.sem = sem;
			this.name = name;
			this.f = f;
			new Thread(this).start();
		}

		@Override
		public void run() {

			try {
				sem.acquire();
				
				for (int i = 0; i < 10; i++) {
					if (f) {
						
						Resource.counter++;
						Thread.sleep(10);

					} else {
						Resource.counter--;
						Thread.sleep(10);
					}
					//System.out.println("f: " + Resource.counter);
				
				
				} 	sem.release();
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

		}
	}

	public static void main(String[] args) throws InterruptedException {
		
		Semaphore semaphore = new Semaphore(1);

		ThredIm one = new ThredIm(semaphore, "one", true);
		ThredIm two = new ThredIm(semaphore, "two", false);
		
		
	    Thread.sleep(3000);


		System.out.println("Counter has value: " + Resource.counter);

	}

}
