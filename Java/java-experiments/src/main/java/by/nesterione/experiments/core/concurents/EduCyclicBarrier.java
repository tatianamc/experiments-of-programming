package by.nesterione.experiments.core.concurents;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class EduCyclicBarrier {
	
	public static void main(String[] args) {
		
		CyclicBarrier barrier = new CyclicBarrier(3, new Act());
		System.out.println("App run");
		new MyTh1(barrier, "1");
		new MyTh1(barrier, "2");
		new MyTh1(barrier, "3");
	}
	
}

class Act implements Runnable {

	@Override
	public void run() {
		System.out.println("DOING ACTION");
	}
	
}

class MyTh1 implements Runnable{

	CyclicBarrier barrier;
	String name;
	public MyTh1(CyclicBarrier barrier, String name) {
		this.barrier = barrier;
		this.name = name;
		new Thread(this).start();
	}
	
	@Override
	public void run() {
		System.out.println(name + " begin");
		try {
			barrier.await();
		} catch (InterruptedException | BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(name + " end");
	}
	
}
