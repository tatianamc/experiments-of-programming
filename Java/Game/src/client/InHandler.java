package client;

import java.io.BufferedReader;
import java.io.IOException;

public class InHandler extends Thread{

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
