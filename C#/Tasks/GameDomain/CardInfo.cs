using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GameDomain
{
		[Serializable]
    public class CardInfo 
    {
			public Color Color { get; set; }
			public CardInfo( Color color )
			{
				Color = color;
			}
    }
}
