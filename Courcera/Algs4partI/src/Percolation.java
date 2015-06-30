
public class Percolation {
    private int N;

    // create N-by-N grid, with all sites blocked
    public Percolation(int N) {
        if(N<=0) throw new IllegalArgumentException();
        this.N = N;
    }

    // open site (row i, column j) if it is not open already
    public void open(int i, int j) {
        checkIndex(i);
        checkIndex(j);

    }

    private void checkIndex(int i) {
        if(i<1||i>N)
            throw new IndexOutOfBoundsException();
    }

    // is site (row i, column j) open?
    public boolean isOpen(int i, int j) {
        checkIndex(i);
        checkIndex(j);

        return false;
    }

    // is site (row i, column j) full?
    public boolean isFull(int i, int j) {
        checkIndex(i);
        checkIndex(j);

        return false;
    }

    // does the system percolate?
    public boolean percolates() {
        return false;
    }

    // test client (optional)
    public static void main(String[] args ) {

    }
}
