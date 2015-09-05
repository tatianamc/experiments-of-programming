using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GameDomain;
using System.Drawing;

namespace GameServer
{
	public class Context
	{
		public CardInfo[] Cards { get; private set; }
		public List<Client> Clients { get; private set; } 

		public Context()
		{
			Clients = new List<Client>();

			Cards = new CardInfo[14];

			Random r = new Random();
			for (int i = 0; i < 6; i++)
			{
				CardInfo c = new CardInfo(Color.FromArgb(r.Next(255), r.Next(255), r.Next(255)));
				Cards[i * 2] = c;
			}
		}
	}
}
