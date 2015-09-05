using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameDomain
{
	[Serializable]
	public class MoveCard
	{
		public int MoveFrom { get; set; }
		public int MoveTo { get; set; }

		public MoveCard( int moveFrom, int moveTo )
		{
			MoveFrom = moveFrom;
			MoveTo = moveTo;
		}
	}
}
