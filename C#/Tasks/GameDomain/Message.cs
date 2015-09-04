using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameDomain
{
	[Serializable]
	public class Message
	{
		public String Action { get; set; }

		public Message( String action )
		{
			Action = action;
		}
	}
}
