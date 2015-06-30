package client;

import java.io.PrintWriter;
import java.util.Scanner;

public class OutHandler extends Thread {

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
