using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using GameDomain;
using System.Threading;

namespace Cards
{
	public class Network
	{
		private IPAddress ip;
		private int port;
		Socket socket;

		private Thread serverActionThread;

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
				/*byte[] data = System.Text.Encoding.UTF8.GetBytes(message);
				socket.Send(data);
				byte[] answer = new byte[1024];
				socket.Receive(answer);

				return Encoding.UTF8.GetString(answer);*/
				NetworkStream stream = new NetworkStream(socket);
				BinaryFormatter bf = new BinaryFormatter();
				bf.Serialize(stream,new Message(message));
			} 
		}

		public event Action<String, String> ServerActionEvent;


		private void ServerListener()
		{
			//// TODO add end of listening
			//while (true)
			//{
			//	// TODO receive any length messages
			//	byte[] data = new byte[1024];
			//	int bytesCount  = socket.Receive(data);
				
			//	// answer 
			//	socket.Send(Encoding.UTF8.GetBytes("{status: OK}"));

			//	// parse answer
			//	String msg = Encoding.UTF8.GetString(data, 0, bytesCount);

			//	String[] request = msg.Split(new char[] { ':' }, 2);
			//	if(request.Length > 1) {
			//		if(request[0].Trim().Equals("move")) {
			//			if (ServerActionEvent != null)
			//			{
			//				ServerActionEvent(request[0].Trim(), request[1].Trim());
			//			}
			//		}
			//	}


			//}
		}

		public CardInfo[] GetCardsAndStartListening()
		{
			NetworkStream stream = new NetworkStream(socket);
			BinaryFormatter bf = new BinaryFormatter();

			CardInfo[] cards = (CardInfo[])bf.Deserialize(stream);

			// run parallel
			serverActionThread = new Thread(ServerListener);
			serverActionThread.Start();

			return cards;
		}

		public void Connect() {
			socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
			socket.Connect(ip, port);
		}

	}
}
