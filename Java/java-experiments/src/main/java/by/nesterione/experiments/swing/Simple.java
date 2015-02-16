package by.nesterione.experiments.swing;

import javax.swing.*;

public class Simple {

	Simple() {
		JFrame jfrm = new JFrame("Simple");
		jfrm.setSize(300, 100);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel jlab = new JLabel("Swing GUI");
		jfrm.add(jlab);
		jfrm.setVisible(true);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			
			@Override
			public void run() {
				new Simple();
			}
		});
	}
}
