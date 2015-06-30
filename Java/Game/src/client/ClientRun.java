package client;

import com.sun.org.omg.CORBA.InitializerHelper;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;
import java.util.TreeMap;


public class ClientRun {
    public static void main(String[] args) throws IOException {
        InetAddress address = Inet4Address.getLocalHost();

        Socket serverSocket = new Socket(address, 9192);


        BufferedReader in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
        PrintWriter out = new PrintWriter(serverSocket.getOutputStream(), true);

        InHandler inHandler = new InHandler(in);
        OutHandler outHandler = new OutHandler(out);

        inHandler.start();
        outHandler.start();

        try {
            inHandler.join();
            outHandler.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class InHandler extends Thread{

    private BufferedReader in;

    public InHandler(BufferedReader in) {
        this.in = in;
    }

    @Override
    public void run() {

        while (true) {
            try {

                System.out.println(in.readLine());

            } catch (IOException e) {
                e.printStackTrace();
            }
        }


    }
}

class OutHandler extends Thread {

    private PrintWriter out;

    public OutHandler(PrintWriter out) {
        this.out = out;
    }

    @Override
    public void run() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            String text = scanner.nextLine();
            out.println(text);
        }
    }
}