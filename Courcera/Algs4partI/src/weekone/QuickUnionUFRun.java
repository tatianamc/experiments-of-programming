package weekone;

/**
 * Created by igor on 29.06.2015.
 */
public class QuickUnionUFRun {

    public static void main(String[] args) {
        QuickUnionUF quickUnionUF = new QuickUnionUF(10);
        quickUnionUF.union(1, 2);
        quickUnionUF.union(2, 3);
        System.out.println(quickUnionUF.connected(1, 3));
        System.out.println(quickUnionUF.connected(1, 4));
    }
}
