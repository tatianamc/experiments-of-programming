using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cards
{
	public class Place
	{
		private static Color BackgroundColor = Color.Gray;
		private static Color RegularBorderColor = Color.Black;
		private static Color SelectedBorderColor = Color.Blue;

		public Card Card { get; set; }
		public bool IsSelected { get; set; }
		public int Id { get; private set; }

		public Point LeftUp { get; set; }
		public int Width { get; set; }
		public int Height { get; set; }

		public Place( Point position, int width, int height, int id )
		{
			LeftUp = position;
			Width = width;
			Height = height;
			IsSelected = false;
			Id = id;
		}

		public void Draw(Graphics g)
		{
			Color border = IsSelected?SelectedBorderColor:RegularBorderColor;

			// Draw card
			if (Card != null)
			{
				g.FillRectangle(new SolidBrush(Card.Color), LeftUp.X, LeftUp.Y, Width, Height);
			} else
			{
				g.FillRectangle(new SolidBrush(BackgroundColor), LeftUp.X, LeftUp.Y, Width, Height);
			}
			Pen pen = new Pen(border, 4);
			g.DrawRectangle(pen, LeftUp.X, LeftUp.Y, Width, Height);
		}

		public event Action<Place> ClickEvent;

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


		public void Click( Point p )
		{
			if (IsHit(p))
			{
				if (ClickEvent != null)
				{
					ClickEvent(this);
				}
			}
		}

	}
}
