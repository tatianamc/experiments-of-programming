import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

/**
 * Created by igor on 28.05.2015.
 */
public class Main {

     public static void main(String[] args) {
        final JFrame frame = new JFrame("JFrame Example");
        final JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        JButton button = new JButton();
        button.setText("Press me");

         // Панель на которой буду рисовать
        final GPanel pn = new GPanel();
        pn.setBackground(new Color(142, 175, 207));

        button.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                List<Line> lines = new ArrayList<Line>();

                Random r = new Random();

                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));
                lines.add(new Line(r.nextInt(300),r.nextInt(300),r.nextInt(300),r.nextInt(300)));

                pn.setLines(lines);
                pn.repaint();

            }
        });


        panel.add(button,BorderLayout.NORTH);
        frame.add(panel);
        frame.setSize(300, 300);


        JScrollPane scrollPane;
        scrollPane = new JScrollPane();
        scrollPane.getViewport().add( pn );
        scrollPane.setSize(new Dimension(300,300));
        panel.add( scrollPane, BorderLayout.CENTER);


        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);


    }

    static class Line {
        private int x1;
        private int y1;
        private int x2;
        private int y2;

        public Line(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public int getX1() {
            return x1;
        }

        public int getY1() {
            return y1;
        }

        public int getX2() {
            return x2;
        }

        public int getY2() {
            return y2;
        }
    }

    static class GPanel extends JPanel {
        public GPanel() {
            setPreferredSize(new Dimension(300, 300));
        }

        private List<Line> lines = new ArrayList<Line>();

        public void setLines(List<Line> lines) {
            this.lines = lines;
        }

        @Override
        public void paint(Graphics g) {
            super.paint(g);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);

            for(Line line : lines) {
                g.drawLine(line.getX1(),line.getY1(),line.getX2(),line.getY2());
            }
            //rectangle originated at 10,10 and end at 240,240
            //g.drawRect(10, 10, 240, 240);
            //filled Rectangle with rounded corners.
            //g.fillRoundRect(50, 50, 100, 100, 80, 80);
        }
    }
}
