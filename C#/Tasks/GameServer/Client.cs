using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;

namespace GameServer
{
	public class Client
	{
		public Socket Socket { get; private set; }
		public String Name { get; set; }

		public Client( String name, Socket socket )
		{
			Name = name;
			Socket = socket;
		}

		public void RunProcessing(Object state)
		{
			bool isError = false;
			while(Socket.Connected&&!isError) {

				// TODO будет ошибка если 
				byte[] data = new byte[1024];

				try
				{
					int bytesCount = Socket.Receive(data);
					String msg = Encoding.UTF8.GetString(data,0,bytesCount);

					Console.ForegroundColor = ConsoleColor.Yellow;
					Console.WriteLine(">>>"+Name + " " + msg + "<<<");
					Console.ResetColor();
				
					Socket.Send( Encoding.UTF8.GetBytes("{status: OK}") );

				} catch (Exception)
				{
					isError = true;

					Console.ForegroundColor = ConsoleColor.Red;
					Console.WriteLine(">>>" + Name + " " + "Bad man! Disconected!!! " + "<<<");
					Console.ResetColor();
				}
			}

			Socket.Shutdown(SocketShutdown.Both);
			Socket.Close();
		}

	}
}
