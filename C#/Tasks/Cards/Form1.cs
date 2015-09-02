using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cards
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void panel1_Paint( object sender, PaintEventArgs e )
		{
			Color c = Color.Green;
			Color b = Color.Black;
			
		}

		private void button1_Click( object sender, EventArgs e )
		{
			Random r = new Random();
			
			for (int i = 0; i < 7; i++)
			{
				Card c = new Card(Color.FromArgb(r.Next(255), r.Next(255), r.Next(255)));
				c.LeftUp = new Point((i + 1) * 40, 20);
				c.Width = 30;
				c.Height = 50;
				cards.Add(c);
				c.ClickEvent += c_ClickEvent;
			}

			repaint();
		}

		void c_ClickEvent( Card obj )
		{
			if (active == obj)
			{
				active = null;

			} else
			{
				active = obj;
			}
		}



		Card active;
		private void repaint()
		{
			Graphics g = panel1.CreateGraphics();
			g.Clear(panel1.BackColor);
			
			cards.ForEach(x=> g.FillRectangle(new SolidBrush(x.Color),x.LeftUp.X,x.LeftUp.Y, x.Width, x.Height));
			if (active != null)
			{
				g.FillRectangle(new SolidBrush(Color.White), active.LeftUp.X, active.LeftUp.Y, active.Width, active.Height);
			}
		}

		List<Card> cards = new List<Card>();

		private void panel1_MouseClick( object sender, MouseEventArgs e )
		{
			cards.ForEach(x => x.Click(e.Location));
			repaint();
		}
	}
}
