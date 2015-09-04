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
using GameDomain;

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
				Place p = new Place(new Point((i + 1) * 70, 300), 60, 80, 7+i);
				p.ClickEvent += c_ClickEvent;
				places.Add(p);
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
							network.Send(String.Format("Card moved from place {0} to {1}", activePlace.Id, obj.Id));
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
			network.ServerActionEvent += network_ServerActionEvent;

			try
			{
				network.Connect();

				CardInfo[] cinf = network.GetCardsAndStartListening();
				for (int i = 0; i < cinf.Length; i++)
				{
					if (cinf[i] != null)
					{
						places[i].Card = new Card(cinf[i].Color);
					}
				}

				repaint();

			} catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			lb_status.Text = network.Status;
		}

		void network_ServerActionEvent( string arg1, string arg2 )
		{
			
			if(arg1.Equals("move")) {
				String[] par = arg2.Split('>');
				if (par.Length > 2)
				{
					int from = int.Parse(par[0]);
					int to = int.Parse(par[2]);

					places[to].Card = places[from].Card;
					repaint();
				}
			}

		}

	}
}
