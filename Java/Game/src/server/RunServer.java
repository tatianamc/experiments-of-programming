package server;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class RunServer {

    public static void main(String[] args) throws IOException {

        ServerSocket serverSocket = new ServerSocket(9192);

        System.out.println("Waiting connections...");
        Socket clientOne = serverSocket.accept();
        System.out.println("Client one connected");
        Socket clientTwo = serverSocket.accept();
        System.out.println("Client two connected");

        BufferedReader in1 = new BufferedReader(new InputStreamReader(clientOne.getInputStream()));
        PrintWriter out1 = new PrintWriter(clientOne.getOutputStream(), true);

        BufferedReader in2 = new BufferedReader(new InputStreamReader(clientTwo.getInputStream()));
        PrintWriter out2 = new PrintWriter(clientTwo.getOutputStream(), true);

        Client clientOneHandler = new Client(out1,in2);
        Client clientTwoHandler = new Client(out2,in1);
        clientOneHandler.start();
        clientTwoHandler.start();

        try {
            clientOneHandler.join();
            clientTwoHandler.join();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }


    }
}

class Client extends Thread{

    private BufferedReader in;
    private PrintWriter out;

    public Client(PrintWriter out, BufferedReader in) {
        this.in = in;
        this.out = out;
    }

    @Override
    public void run() {

        while (true) {
            try {

                String string = in.readLine();
                out.println(string);

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}