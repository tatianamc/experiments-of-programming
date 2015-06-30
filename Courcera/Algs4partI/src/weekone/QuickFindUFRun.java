package weekone;

/**
 * Created by igor on 29.06.2015.
 */
public class QuickFindUFRun {
    public static void main(String[] args) {
        QuickFindUF quickFindUF = new QuickFindUF(10);
        quickFindUF.union(1,2);
        quickFindUF.union(2,3);
        System.out.println(quickFindUF.connected(1,3));
        System.out.println(quickFindUF.connected(1,4));
    }
}
