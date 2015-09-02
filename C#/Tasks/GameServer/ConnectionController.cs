using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace GameServer
{
	public class ConnectionController
	{
		public String Status { get; private set; }

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

			int counter = 0;
			while (true)
			{
				Socket socket = server.AcceptSocket();

				Console.ForegroundColor = ConsoleColor.Red;
				Console.WriteLine("Client connected: ", socket.LocalEndPoint);
				Console.ResetColor();

				Client client = new Client("Client " + counter++, socket);
				clients.Add(client);
				ThreadPool.QueueUserWorkItem( client.RunProcessing );
				

			}
			
		}
	}
}
