using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Security;
using System.Net.Sockets;
using System.Security.Authentication;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace https
{
    class Program
    {
        public static string SuccessHeaders(int contentLength)
        {
            StringBuilder builder = new StringBuilder();
            builder.Append("HTTP/1.1 200 OK").Append("\r\n");
            builder.Append("Date: ").Append(DateTime.Now).Append("\r\n");
            builder.Append("Server: nesterione-server").Append("\r\n");
            builder.Append("Content-Type: text/html; charset=UTF-8").Append("\r\n");
            builder.Append("Content-Length: ").Append(contentLength).Append("\r\n");
            builder.Append("Connection: close").Append("\r\n");
            builder.Append("\r\n");

            return builder.ToString();
        }

        private static string AnswerPage(String val) {
            StringBuilder bodyBuilder = new StringBuilder();
            bodyBuilder.Append("You entered value:");
            bodyBuilder.Append("<br><br>");
            bodyBuilder.Append(val);
            bodyBuilder.Append("<br>");
            bodyBuilder.Append("<br>");
            bodyBuilder.Append("<a href='/' > Open Index Page </a> ");
            String body = bodyBuilder.ToString();

            // warning, if body contains non-ascii symbols next record can be incorect
            return String.Concat(SuccessHeaders(body.Length), body);
        }

        private static string BadAnswerPage()
        {
            StringBuilder bodyBuilder = new StringBuilder();
            bodyBuilder.Append("Something was bad");
            bodyBuilder.Append("<br>");
            bodyBuilder.Append("<a href='/' > Open Index Page </a> ");
            String body = bodyBuilder.ToString();

            // warning, if body contains non-ascii symbols next record can be incorect
            return String.Concat(SuccessHeaders(body.Length), body);
        }

        private static string IndexPage()
        {
            StringBuilder bodyBuilder = new StringBuilder();
            bodyBuilder.Append("<form method='post'>");
            bodyBuilder.Append("hi, I'm https-server, input number:");
            bodyBuilder.Append("<br>");
            bodyBuilder.Append("<input type='text' name='val' >");
            bodyBuilder.Append("<br>");
            bodyBuilder.Append("<input type='submit' >");
            bodyBuilder.Append("</form>");
            String body = bodyBuilder.ToString();

            // warning, if body contains non-ascii symbols next record can be incorect
            return String.Concat(SuccessHeaders(body.Length), body);
        }

       
        static X509Certificate serverCertificate = null;

        static void ProcessClient(Object obj)
        {
            TcpClient client = (TcpClient)obj;

            // A client has connected. Create the 
            // SslStream using the client's network stream.
            SslStream sslStream = new SslStream(client.GetStream(), false);
            // Authenticate the server but don't require the client to authenticate.
            try
            {
                sslStream.AuthenticateAsServer(serverCertificate,
                    false, SslProtocols.Tls, true);
                // Display the properties and settings for the authenticated stream.

                // Set timeouts for the read and write to 5 seconds.
                sslStream.ReadTimeout = 5000;
                sslStream.WriteTimeout = 5000;
                // Read a message from the client.   
                Console.WriteLine("Waiting for client message...");
                
                string messageData = ReadMessage(sslStream);

                Console.WriteLine("request:");
                Console.WriteLine(messageData);

                string page = "";
                if (messageData.StartsWith("POST"))
                {
                    Regex r = new Regex("\r\n\r\n");
                    String[] request = r.Split(messageData, 2);

                    if(request.Length!=2)
                    {
                        page = BadAnswerPage();
                    } else
                    {
                        String val = request[1].Split('=')[1];
                        page = AnswerPage(val);
                    }
                    
                } else
                {
                    page = IndexPage();
                }

                Console.WriteLine("response:");
                Console.WriteLine(page);
                byte[] message = Encoding.UTF8.GetBytes(page);
                sslStream.Write(message,0,message.Length);
                sslStream.Flush();
            }
            catch (AuthenticationException e)
            {
                Console.WriteLine("Exception: {0}", e.Message);
                if (e.InnerException != null)
                {
                    Console.WriteLine("Inner exception: {0}", e.InnerException.Message);
                }
                Console.WriteLine("Authentication failed - closing the connection.");
            }
            finally
            {
                // The client stream will be closed with the sslStream
                // because we specified this behavior when creating
                // the sslStream.
                sslStream.Close();
                client.Close();
            }
        }

        static void Main(string[] args)
        {
            serverCertificate = X509Certificate.CreateFromCertFile("output2.cer");
            TcpListener listener = new TcpListener(IPAddress.Any, 8088);
            listener.Start();
            Console.WriteLine("Server run on: https://localhost:8088 ");
            while (true)
            {
                TcpClient client = listener.AcceptTcpClient();
                ThreadPool.QueueUserWorkItem(ProcessClient, client);
            }
        }

        static string ReadMessage(SslStream sslStream)
        {
            StringBuilder messageData=new StringBuilder();
            try {
                byte[] buffer = new byte[2048];
                int bytes = -1;
                do
                {
                    // Read the client's test message.
                    bytes = sslStream.Read(buffer, 0, buffer.Length);

                    // Use Decoder class to convert from bytes to UTF8
                    // in case a character spans two buffers.
                    Decoder decoder = Encoding.UTF8.GetDecoder();
                    char[] chars = new char[decoder.GetCharCount(buffer, 0, bytes)];
                    decoder.GetChars(buffer, 0, bytes, chars, 0);
                    messageData.Append(chars);
                    
                } while (bytes != 0);
            } catch(Exception) { }

            return messageData.ToString();
        }
    }
}

