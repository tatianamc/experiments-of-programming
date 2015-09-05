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

		public void Send(Message message)
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
				bf.Serialize(stream,message);
			} 
		}

		public event Action<Message> ServerActionEvent;


		private void ServerListener()
		{
			bool isError = false;
			// TODO add end of listening
			while (!isError)
			{
				NetworkStream stream = new NetworkStream(socket);
				BinaryFormatter bf = new BinaryFormatter();
				try
				{
					Message msg = (Message)bf.Deserialize(stream);

					if (ServerActionEvent != null)
					{
						ServerActionEvent(msg);
					}
				} 
				// TODO catch other type exception
				catch (Exception ex)
				{
					isError = true;
				}
			}
		}

		public void Connect() {
			socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
			socket.Connect(ip, port);

			// run parallel
			serverActionThread = new Thread(ServerListener);
			serverActionThread.Start();
		}

	}
}
