using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Runtime.Serialization.Formatters.Binary;

namespace GameServer
{
	public class ConnectionController
	{
		public String Status { get; private set; }
		private Context context;

		public ConnectionController()
		{
			Status = "Not running";
		}

		List<Client> clients = new List<Client>();

		public void Run()
		{
			Status = "Running. Available for connection.";
			TcpListener server = new TcpListener(IPAddress.Parse("127.0.0.1"), 8089);
			server.Start();

			// Create game contex, one for all connected users
			context = new Context();

			int counter = 0;
			while (true)
			{
				Socket socket = server.AcceptSocket();

				Console.ForegroundColor = ConsoleColor.Red;
				Console.WriteLine("Client connected: sending data");
				Console.ResetColor();

				Client client = new Client("Client " + counter++, socket);

				BinaryFormatter bf = new BinaryFormatter();
				bf.Serialize(client.stream, new GameDomain.Message("data", context.Cards));

				Console.ForegroundColor = ConsoleColor.Red;
				Console.WriteLine("successful", socket.LocalEndPoint);
				Console.ResetColor();

				clients.Add(client);
				ThreadPool.QueueUserWorkItem( client.RunProcessing );
			}
			
		}
	}
}
