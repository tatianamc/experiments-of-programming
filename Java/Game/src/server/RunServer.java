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

        GameContext context = new GameContext();
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

class GameContext {
    private int activeUser = 1;

    public int getActiveUser() {
        return activeUser;
    }

    public void setActiveUser(int activeUser) {
        this.activeUser = activeUser;
    }

    public void complete() {
        if(activeUser==1)
            activeUser = 2;
        else activeUser = 1;
    }
}

class Client extends Thread{

    private BufferedReader in;
    private PrintWriter outOther;
    private PrintWriter out;
    private GameContext context;
    private int id;

    public Client(int id, PrintWriter outOther, PrintWriter out, BufferedReader in, GameContext context) {
        this.id = id;
        this.in = in;
        this.outOther = outOther;
        this.out = out;
        this.context = context;
    }

    @Override
    public void run() {

        while (true) {
            try {
                String string = in.readLine();
                if(context.getActiveUser()==id) {
                    outOther.println(string);
                    context.complete();
                } else {
                    out.println("Wait your course");
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}