using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using GameDomain;
using System.Threading;

namespace GameServer
{
	public class Client
	{
		private Socket socket;
		public NetworkStream stream;
		
		public String Name { get; set; }

		public Client( String name, Socket socket)
		{
			Name = name;
			this.socket = socket;
			this.stream = new NetworkStream(socket,true);
		}

		public void SendEventToClient(Message msg)
		{
			BinaryFormatter bf = new BinaryFormatter();
			bf.Serialize(stream, msg);
		}

		public void RunProcessing(Object state)
		{
			bool isError = false;
			while( !isError) {
				
				// TODO будет ошибка если 
				byte[] data = new byte[1024];

				try
				{
					BinaryFormatter bf = new BinaryFormatter();

					Message msg = (Message)bf.Deserialize(stream);

					Console.ForegroundColor = ConsoleColor.Yellow;
					Console.WriteLine(">>>"+Name + " " + msg.Action + "<<<");
					Console.ResetColor();
					Thread.Sleep(4000);
				
				} catch (Exception)
				{
					isError = true;

					Console.ForegroundColor = ConsoleColor.Red;
					Console.WriteLine(">>>" + Name + " " + "Bad man! Disconected!!! " + "<<<");
					Console.ResetColor();
				}
			}

			stream.Close();
		
		}


	}
}
