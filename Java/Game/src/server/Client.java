package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Client extends Thread{

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

        while (!context.isEnd) {
            try {
                String string = in.readLine();
                if(context.getActiveUser()==id) {
                    string = string.trim().toLowerCase();

                    if("pass".equals(string)) {
                        outOther.println("You Win!");
                        out.println("You Lose!");
                        context.isEnd = true;
                    } else {

                        char ch = string.charAt(0);
                        if(ch==context.getActiveChar()) {

                            boolean isExist = true;
                            try {
                                isExist = WordExistsChecker.check(string);
                            } catch (IOException e) {
                                System.out.println("Warning: word checker not available");
                            }
                            if(isExist) {
                                context.setActiveChar(string.charAt(string.length()-1));
                                outOther.println(string+" "+"enter word start with '"+context.getActiveChar()+"'");
                                out.println("ok");
                                context.complete();
                            } else {
                                out.println("Sorry, but your word not exists, try again");
                            }
                        } else {
                            out.println("Sorry, enter word start with '"+context.getActiveChar()+"'");
                        }


                    }
                } else {
                    out.println("Wait...");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
