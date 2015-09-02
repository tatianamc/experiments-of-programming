using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace Cards
{
	public class Network
	{
		private IPAddress ip;
		private int port;
		Socket socket;

		public Network( IPAddress ip, int port )
		{
			this.ip = ip;
			this.port = port;
		}

		public String Status
		{
			get
			{
				if (socket != null)
				{
					if (socket.Connected)
					{
						return "Connected";
					}
				}

				return "Disconnected";
			}
		}

		public void Send(String message)
		{
			if (socket != null)
			{
				byte[] data = System.Text.Encoding.UTF8.GetBytes (message);
				socket.Send(data);
				byte[] answer = new byte[1024];
				socket.Receive(answer);

			}
		}

		public void Connect() {
			socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
			socket.Connect(ip, port);
		}

	}
}
