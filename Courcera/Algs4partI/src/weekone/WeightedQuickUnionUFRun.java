package weekone;

/**
 * Created by igor on 29.06.2015.
 */
public class WeightedQuickUnionUFRun {
    public static void main(String[] args) {
        WeightedQuickUnionUF weightedQuickUnionUF = new WeightedQuickUnionUF(10);
        weightedQuickUnionUF.union(1, 2);
        weightedQuickUnionUF.union(2, 3);
        System.out.println(weightedQuickUnionUF.connected(1, 3));
        System.out.println(weightedQuickUnionUF.connected(1, 4));
    }
}
