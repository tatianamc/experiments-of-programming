using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace GameServer
{
	public class ConnectionController
	{
		public String Status { get; private set; }

		public ConnectionController()
		{
			Status = "Not running";
		}

		List<Socket> clients = new List<Socket>();

		public void Run()
		{
			Status = "Running. Available for connection.";
			TcpListener server = new TcpListener(IPAddress.Parse("127.0.0.1"), 8089);
			server.Start();

			while (true)
			{
				Socket client = server.AcceptSocket();

				Console.ForegroundColor = ConsoleColor.Red;
				Console.WriteLine("Client connected: ", client.LocalEndPoint);
				Console.ResetColor();
				clients.Add(client);
			}
			
		}
	}
}
