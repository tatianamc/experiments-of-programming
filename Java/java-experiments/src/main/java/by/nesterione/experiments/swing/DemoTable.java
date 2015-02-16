package by.nesterione.experiments.swing;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.SwingUtilities;

public class DemoTable  extends JFrame{

	
	DemoTable() {
			
		Object[][] data = {
				{"sdf0","345","435"},	
				{"fdh","435","5"},
				{"fgh","345","43"},
				{"ert","ret","53"},
				{"er","34","435"},
				{"ert","435","345"}
		};
		
		String[] colHeads = {"!!435","!!sdf","!!sdf"};
		
		JTable jt = new JTable(data, colHeads);
		JScrollPane jsp = new JScrollPane(jt);
		
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 300);
		frame.add(jsp);
		frame.setVisible(true);
	}
	
	

	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			
			@Override
			public void run() {
				new DemoTable();
			}
		});
	}
}
