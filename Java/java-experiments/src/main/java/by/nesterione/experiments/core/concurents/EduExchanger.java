package by.nesterione.experiments.core.concurents;

import java.util.concurrent.Exchanger;

public class EduExchanger {
	
	public static void main(String[] args) {
		Exchanger<String> ex = new Exchanger<>();
		UseString us = new UseString(ex);
		MakeString ms = new MakeString(ex);
	}
}

class MakeString implements Runnable{
	Exchanger<String> exchanger;
	String str;
	
	MakeString(Exchanger<String> exchanger) {
		this.exchanger = exchanger;
		str = new String();
		new Thread(this).start();
	}

	@Override
	public void run() {
		for(int i = 0; i< 4; i++) {
			str = "SendedMessage_"+i;
			try {
				String s = new String(str);
				str = exchanger.exchange(str);
				System.out.println("SEND" + s);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

class UseString implements Runnable {
	Exchanger<String> exchanger;
	String str;
	UseString(Exchanger<String> exchanger) {
		this.exchanger = exchanger;
		str  = new String();
		new Thread(this).start();
	}
	@Override
	public void run() {
		for(int i = 0; i< 4; i++) {
			try {
				str = exchanger.exchange(new String());
				System.out.println("Get: " + str);
			} catch (InterruptedException ex) {
				ex.printStackTrace();
			}
		}
	}
	
	
}
