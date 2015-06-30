package client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.Socket;


public class ClientRun {
    public static void main(String[] args) throws IOException {
        InetAddress address = Inet4Address.getLocalHost();

        Socket serverSocket = new Socket(address,9192);

        ClientChecker clientChecker = new ClientChecker(serverSocket);
        ClientSender clientSender = new ClientSender(serverSocket);


        clientChecker.start();
        clientSender.start();

        try {
            clientChecker.join();
            clientChecker.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

       /* ClientWorker worker = new ClientWorker(serverSocket);

        worker.run();

        try {
            worker.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }*/

    }
}

class ClientChecker extends Thread {
    private Socket serverSocket;
    private PrintWriter out;
    private BufferedReader in;

    public ClientChecker(Socket serverSocket) throws IOException {
        this.serverSocket = serverSocket;

        out = new PrintWriter(serverSocket.getOutputStream(), true);
        in = new BufferedReader(
                new InputStreamReader(serverSocket.getInputStream()));
    }

    @Override
    public void run() {

        try {
            while (true) {
                System.out.println(in.readLine());
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ClientSender extends Thread {

    private Socket serverSocket;
    private PrintWriter out;
    private BufferedReader in;

    public ClientSender(Socket serverSocket) throws IOException {
        this.serverSocket = serverSocket;

        out = new PrintWriter(this.serverSocket.getOutputStream(), true);
        in = new BufferedReader(
                new InputStreamReader(serverSocket.getInputStream()));
    }



    @Override
    public void run() {

        boolean stillAlive = true;
        int i=0;
        while (stillAlive) {

            try {
                out.println("Action on client " + i++);
                Thread.sleep(1000);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class ClientWorker extends Thread {

    private Socket serverSocket;
    private PrintWriter out;
    private BufferedReader in;

    public ClientWorker(Socket serverSocket) throws IOException {
        this.serverSocket = serverSocket;

        out = new PrintWriter(this.serverSocket.getOutputStream(), true);
        in = new BufferedReader(
                new InputStreamReader(serverSocket.getInputStream()));
    }



    @Override
    public void run() {

        boolean stillAlive = true;
        while (stillAlive) {

            try {
                out.println("Hi, Dear server, what time is it now? ");
                System.out.println(in.readLine());
                Thread.sleep(1000);

            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}