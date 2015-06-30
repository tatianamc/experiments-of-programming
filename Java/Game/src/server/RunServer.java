package server;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

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
        ClientAnswer clientAnswer1 = new ClientAnswer(out1);
        ClientProcessor clientProcessor1 = new ClientProcessor(in1);

        BufferedReader in2 = new BufferedReader(new InputStreamReader(clientTwo.getInputStream()));
        PrintWriter out2 = new PrintWriter(clientTwo.getOutputStream(), true);
        ClientAnswer clientAnswer2 = new ClientAnswer(out1);
        ClientProcessor clientProcessor2 = new ClientProcessor(in1);

        GameContext one = new GameContext(clientAnswer1,clientProcessor1);
        GameContext two = new GameContext(clientAnswer2,clientProcessor2);
        one.startGame();
        two.startGame();
        one.join();
        two.join();
    }
}

class GameContext {

    ClientAnswer clientAnswer;
    ClientProcessor clientProcessor;

    public GameContext(ClientAnswer clientAnswer, ClientProcessor clientProcessor) {
        this.clientAnswer = clientAnswer;
        this.clientProcessor = clientProcessor;
    }

    public void startGame() {
        clientAnswer.start();
        clientProcessor.start();
    }

    public void join() {
        try {
            clientAnswer.join();
            clientProcessor.join();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

class ClientAnswer extends Thread {
    private PrintWriter out;

    public ClientAnswer(PrintWriter out) {
        this.out = out;
    }

    @Override
    public void run() {
        int i = 0;
        while (true) {
            try {
                Thread.sleep(2000);
                out.println("Action on server"+i++);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class ClientProcessor extends Thread {

    private BufferedReader in;

    public ClientProcessor(BufferedReader in) {
        this.in = in;
    }

    @Override
    public void run() {

        System.out.println("Listen client");
        while (true) {
            try {

                System.out.println(in.readLine());
                System.out.println("get");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
