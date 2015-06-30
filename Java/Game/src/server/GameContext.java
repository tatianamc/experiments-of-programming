package server;

public class GameContext {
    private int activeUser = 1;
    private char activeChar = 'a';
    public boolean isEnd = false;

    public char getActiveChar() {
        return activeChar;
    }

    public void setActiveChar(char activeChar) {
        this.activeChar = activeChar;
    }

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
