using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using GameDomain;

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

		public String Send(String message)
		{
			if (socket != null)
			{
				byte[] data = System.Text.Encoding.UTF8.GetBytes(message);
				socket.Send(data);
				byte[] answer = new byte[1024];
				socket.Receive(answer);

				return Encoding.UTF8.GetString(answer);
			} else
			{
				return "No connected";
			}
		}

		public CardInfo[] GetCards()
		{
			NetworkStream stream = new NetworkStream(socket);
			BinaryFormatter bf = new BinaryFormatter();
			return (CardInfo[])bf.Deserialize(stream);
		}

		public void Connect() {
			socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
			socket.Connect(ip, port);
		}

	}
}
