using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;

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

		List<Place> places;
		private void button1_Click( object sender, EventArgs e )
		{
			places = new List<Place>();

			for (int i = 0; i < 7; i++)
			{
				Place p = new Place(new Point((i + 1) * 70, 60), 60, 80, i);
				p.ClickEvent += c_ClickEvent;
				places.Add(p);
			}

			for (int i = 0; i < 7; i++)
			{
				Place p = new Place(new Point((i + 1) * 70, 300), 60, 80, 6+i);
				p.ClickEvent += c_ClickEvent;
				places.Add(p);
			}


			Random r = new Random();
			
			for (int i = 0; i < 6; i++)
			{
				Card c = new Card(Color.FromArgb(r.Next(255), r.Next(255), r.Next(255)));
				places[i * 2].Card = c;
			}

			repaint();
		}


		Place activePlace;

		void c_ClickEvent( Place obj )
		{
			if(activePlace!=null) {

				if (activePlace == obj)
				{
					obj.IsSelected = false;
					activePlace = null;
				} else
				{
					if (obj.Card == null)
					{
						obj.Card = activePlace.Card;

						if (network != null)
						{
							lb_answer.Text = network.Send(String.Format("Card moved from place {0} to {1}", activePlace.Id, obj.Id));
						}

						activePlace.Card = null;
						activePlace.IsSelected = false;
						activePlace = null;

					} else
					{
						MessageBox.Show("Эй, там же карта лежит!");
					}
				}

			} else {

				if (obj.Card != null)
				{
					activePlace = obj;
					activePlace.IsSelected = true;
				}

			}

		}



		Card active;
		private void repaint()
		{
			Graphics g = panel1.CreateGraphics();
			g.Clear(panel1.BackColor);
			places.ForEach(x => x.Draw(g));
		}

		List<Card> cards = new List<Card>();

		private void panel1_MouseClick( object sender, MouseEventArgs e )
		{
			places.ForEach(x => x.Click(e.Location));
			repaint();
		}

		Network network;
		private void btn_connect_Click( object sender, EventArgs e )
		{
			network = new Network( IPAddress.Parse(tb_ip.Text), int.Parse(tb_port.Text));
			try
			{
				network.Connect();
			} catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			lb_status.Text = network.Status;
		}
	}
}
