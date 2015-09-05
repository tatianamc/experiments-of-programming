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
		private Context context;
		
		public String Name { get; set; }

		public Client( String name, Socket socket, Context context)
		{
			Name = name;
			this.socket = socket;
			this.stream = new NetworkStream(socket,true);
			this.context = context;
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

					// TODO дополнительная проверка на возможность данного действия 
					if(msg.Action.Equals("move")) {
						MoveCard move = msg.Data as MoveCard;
						if (move != null)
						{

							// TODO добавить проверку
							context.Cards[move.MoveTo] = context.Cards[move.MoveFrom];
							context.Cards[move.MoveFrom] = null;

							foreach (Client c in context.Clients)
							{
								c.SendEventToClient(msg);
							}

						}
					}

					//if (msg.Data is String)
					//{	
					//	Console.ForegroundColor = ConsoleColor.Yellow;
					//	Console.WriteLine(">>>" + Name + " " + msg.Action+":"+ msg.Data + "<<<");
					//	Console.ResetColor();
					//}
				
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
