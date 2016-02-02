using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace TimeApp
{
    class Program
    {
        static void Main(string[] args)
        {
            
            bool isServer = true;

            String ip = "127.0.0.1";

            if (args.Length>=1)
            {
                ip = args[0];
                isServer = false;
            }

            if(isServer)
            {
                Server.Run(8080);
            } else
            {
                Client.Run(ip,8080);
            }

            Console.ReadKey();
        }
    }

    public static class Server
    {
        public static void Run(int port)
        {
            try
            {
                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                IPEndPoint ip = new IPEndPoint(IPAddress.Any, port);
                socket.Bind(ip);
                socket.Listen(10);
                Console.WriteLine("Server run at: {0}", port);
                while (true)
                {
                    Socket client = socket.Accept();
                    byte[] buff = new byte[1024];
                    client.Receive(buff);
                    String data = Encoding.UTF8.GetString(buff);
                    // тут можно еще пробелы отсекать (нули заменяются символами)
                    Console.WriteLine(data);
                    client.Shutdown(SocketShutdown.Both);
                    client.Close();
                }

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }
    }

    public static class Client
    {
        public static void Run(String ipString, int port)
        {
            try
            {
                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                IPEndPoint ip = new IPEndPoint(IPAddress.Parse(ipString), port);
                socket.Connect(ip);


                byte[] buff = new byte[1024];
                String data = DateTime.Now.ToString();
                buff = Encoding.UTF8.GetBytes(data);
                socket.Send(buff);

                Console.WriteLine("send date: " + data);
                socket.Shutdown(SocketShutdown.Both);
                socket.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
