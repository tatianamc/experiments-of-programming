package by.nesterione.experiments.core.concurents;

import java.util.concurrent.Phaser;
//Для контроля происходящего при переходе к следующей фазе
// нужно переопределить onAdvance()
// метод вызывается средой выполнения когда фазер меняет фазы
public class EduPhaser {
	public static void main(String[] args) {
		Phaser phaser = new Phaser(1);
		int curPhase;
		
		new Thr(phaser, "A");
		new Thr(phaser, "B");
		new Thr(phaser, "C");
		
		curPhase = phaser.getPhase();
		phaser.arriveAndAwaitAdvance();
		System.out.println("Phase "+ curPhase + " end");
		
		curPhase = phaser.getPhase();
		phaser.arriveAndAwaitAdvance();
		System.out.println("Phase "+ curPhase + " end");
		
		curPhase = phaser.getPhase();
		phaser.arriveAndAwaitAdvance();
		System.out.println("Phase "+ curPhase + " end");
		
		phaser.arriveAndDeregister();
		
		if(phaser.isTerminated()) {
			System.out.println("The Phaser was terminated");
		}
	}
}

class Thr implements Runnable {
	Phaser phaser;
	String name;
	
	Thr(Phaser phaser, String name) {
		this.phaser = phaser;
		this.name = name;
		this.phaser.register();
		new Thread(this).start();
	}
	
	public void run() {
		System.out.println(name + ": begin phase one");
		phaser.arriveAndAwaitAdvance();
		
		try {
			Thread.sleep(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println(name + ": begin phase two");
		phaser.arriveAndAwaitAdvance();
		
		try {
			Thread.sleep(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println(name + "Begin Phase Three");
		phaser.arriveAndDeregister();
	}
	
}
