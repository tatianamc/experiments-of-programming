package by.nesterione.experiments.core.concurents;

import java.util.concurrent.locks.ReentrantLock;

public class EduLocks {
	
	public static void main(String[] args) {
		ReentrantLock lock = new ReentrantLock();
		
		new LockThread(lock, "A");
		new LockThread(lock, "B");
		
	}
	
}

class Shared {
	public static int count = 0;
}

class LockThread implements Runnable {

	String name;
	ReentrantLock lock;
	public LockThread(ReentrantLock lk, String n) {
		lock = lk;
		name = n;
		new Thread(this).start();
	}
	
	@Override
	public void run() {
		System.out.println("Запуск " + name);
		try {
			System.out.println(name + " ожидает блокировки");
			lock.lock();
			System.out.println(name + " блокирует счетчик");
			Shared.count++;
			System.out.println(name + " : "+ Shared.count);
			//Разрешается контекстное переключение
			System.out.println(name + ": контекстное переключение");
			Thread.sleep(1000);
		} catch (InterruptedException ex) {
			System.out.println(name + "ex");
		} finally {
			//unlock
			System.out.println(name + " разблокировка");
			lock.unlock();
		}
	}
	
}