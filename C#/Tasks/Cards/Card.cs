using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cards
{
	public class Card
	{
		public Color Color { get; set; }
		public Point LeftUp { get; set; }
		public int Width { get; set; }
		public int Height { get; set; }

		public Card( Color color )
		{
			Color = color;
		}

		private bool IsHit( Point p )
		{

			if (p.X > LeftUp.X && p.X < (LeftUp.X + Width))
			{
				if (p.Y > LeftUp.Y && p.Y < (LeftUp.Y + Height))
				{
					return true;
				}
			}

			return false;
		}

		public event Action<Card> ClickEvent;

		public void Click( Point p ) {
			if(IsHit(p)) {
				if(ClickEvent!=null) {
					ClickEvent(this);
				}
			}
		}


	}
}
