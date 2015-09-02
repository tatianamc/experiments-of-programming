using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Threading;

namespace GameServer
{
	class Program
	{

		static void Main( string[] args )
		{
			 Console.WriteLine("Game server version 0.01 / By @nesterione");
			 Console.WriteLine("Server service is running");
			 ConnectionController controller = new ConnectionController();
			 Thread threadController;

			 String command = "";
			 do
			 {
				 Console.WriteLine("");
				 Console.ForegroundColor = ConsoleColor.Cyan;
				 command = Console.ReadLine().Trim();
				 Console.ResetColor();
				 Console.WriteLine("");

				 switch (command)
				 {
					 case "help":
						 Console.WriteLine("Game server version 0.01 / By @nesterione");
						 Console.WriteLine("");
						 Console.WriteLine("help : open manual");
						 Console.WriteLine("status : print status of server");
						 Console.WriteLine("start : run server");
						 Console.WriteLine("stop : stop server");
						 Console.WriteLine("restart: restart server");
						 break;
					 case "status":
						 Console.WriteLine(controller.Status);
						 break;
					 case "start":
						 // TODO добавить проверку на запущенность сервера
						 threadController = new Thread(controller.Run);
						 threadController.Start();
						 Console.WriteLine("Ready for connecting...");

						 break;
					 default:
						 Console.WriteLine("Invalid command / type help to view available commands");
						 break;
					 
						 
				 }

			 } while (!command.Equals("exit"));

			// TODO добавить остановку сервера
		}
	}
}
