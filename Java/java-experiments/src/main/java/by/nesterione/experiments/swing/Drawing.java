package by.nesterione.experiments.swing;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Insets;
import java.util.Random;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

class DPanel extends JPanel{
	//Размеры внутренней части панели
	Insets ins; 
	Random rand;
	
	DPanel() {
		setBorder(BorderFactory.createLineBorder(Color.blue,5));
		rand = new Random();
	}
	
	
	public void paintComponent(Graphics g) {
		super.paintComponents(g);
		
		
		int x, y, x2, y2;
		int height = getHeight();
		int width = getWidth();
		
		ins = getInsets();
		
		for(int i = 0 ; i < 10; i++) {
			x = rand.nextInt(width-ins.left);
			y = rand.nextInt(height - ins.bottom);
			x2 = rand.nextInt(width - ins.left);
			y2 = rand.nextInt(height - ins.bottom);
			
			g.drawLine(x, y, x2, y2);
		}
	}
}

public class Drawing {
	JLabel jlab;
	DPanel pp;
	public Drawing() {
		JFrame jfrm = new JFrame("Paint");
		jfrm.setSize(200, 200);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		pp = new DPanel();
		jfrm.add(pp);
		jfrm.setVisible(true);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			
			@Override
			public void run() {
				new Drawing();
			}
		});
	}
}
