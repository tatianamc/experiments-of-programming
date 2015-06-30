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

        GameContext context = new GameContext();

        BufferedReader in1 = new BufferedReader(new InputStreamReader(clientOne.getInputStream()));
        PrintWriter out1 = new PrintWriter(clientOne.getOutputStream(), true);
        out1.println("You are second, wait ...");

        BufferedReader in2 = new BufferedReader(new InputStreamReader(clientTwo.getInputStream()));
        PrintWriter out2 = new PrintWriter(clientTwo.getOutputStream(), true);
        out2.println("You are first, enter any word start with '"+context.getActiveChar()+"'");

        Client clientOneHandler = new Client(1,out1, out2, in2, context);
        Client clientTwoHandler = new Client(2,out2, out1, in1, context);

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

