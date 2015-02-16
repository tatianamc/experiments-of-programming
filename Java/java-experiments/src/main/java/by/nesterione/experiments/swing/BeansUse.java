package by.nesterione.experiments.swing;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class BeansUse extends JFrame {

	public BeansUse(){
		JFrame fr = new JFrame();
		fr.setSize(300,300);
		fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Colors colors = new Colors();
		colors.setRectangular(true);
		fr.add(colors);
		fr.setVisible(true);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			
			@Override
			public void run() {
				new BeansUse();
			}
		});
	}
}
