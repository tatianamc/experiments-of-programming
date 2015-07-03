
public class Percolation {
    private static final byte OPEN = 1;
    private static final byte BOTTOM_CONNECTED = 2;
    private static final byte OPEN_AND_BOTTOM = 3;

    private boolean isPercolates = false;
    private int N;
    private WeightedQuickUnionUF uf;
    private int top;
    private byte[] flagsVector;

    // create N-by-N grid, with all sites blocked
    public Percolation(int N) {
        if (N <= 0) throw new IllegalArgumentException();
        this.N = N;

        this.uf = new WeightedQuickUnionUF(N * N + 1);

        // At one less
        this.top = N * N;
        flagsVector = new byte[N * N];
        int i = N * N - N;
        while (i < flagsVector.length) {
            flagsVector[i++] = BOTTOM_CONNECTED;
        }
    }

    private void openVectorItem(int index) {
        if (flagsVector[index] == BOTTOM_CONNECTED) {
            flagsVector[index] = OPEN_AND_BOTTOM;
        } else {
            flagsVector[index] = OPEN;
        }
    }

    private boolean isBottomConnected(int index) {
        return flagsVector[index] == OPEN_AND_BOTTOM || flagsVector[index] == BOTTOM_CONNECTED;
    }

    // DONE open site (row i, column j) if it is not open already
    public void open(int i, int j) {
        checkIndex(i);
        checkIndex(j);

        if (!isOpen(i, j)) {

            int flatIdxCenter = toFlatIndex(i, j);
            openVectorItem(flatIdxCenter);

            if (i == 1) {
                uf.union(flatIdxCenter, this.top);
            }

            int[][] idx = {
                    {i - 1, j},
                    {i + 1, j},
                    {i, j + 1},
                    {i, j - 1}
            };

            boolean conToBot = false;
            for (int[] anIdx : idx) {

                int curI = anIdx[0];
                int curJ = anIdx[1];

                if (exists(curI, curJ) && isOpen(curI, curJ)) {
                    int flatIdx = toFlatIndex(curI, curJ);

                    int idd = uf.find(flatIdx);
                    conToBot = conToBot || isBottomConnected(idd);
                }
            }


            for (int[] anIdx : idx) {
                int curI = anIdx[0];
                int curJ = anIdx[1];


                if (exists(curI, curJ) && isOpen(curI, curJ)) {
                    int flatIdx = toFlatIndex(curI, curJ);
                    uf.union(flatIdx, flatIdxCenter);
                }
            }

            int newRoot = uf.find(flatIdxCenter);

            if (conToBot || isBottomConnected(flatIdxCenter)) {
                flagsVector[newRoot] = OPEN_AND_BOTTOM;
            }

            if (!isPercolates && uf.connected(flatIdxCenter, this.top)) {
                if (isBottomConnected(newRoot)) {
                    isPercolates = true;
                }
            }

        }
    }

    private boolean exists(int i, int j) {
        return (0 < i && i <= N) && (0 < j && j <= N);
    }

    private void checkIndex(int i) {
        if (i <= 0 || i > N) throw new IndexOutOfBoundsException("row index i out of bounds");
    }

    // DONE is site (row i, column j) open?
    public boolean isOpen(int i, int j) {
        checkIndex(i);
        checkIndex(j);
        int index = toFlatIndex(i, j);

        return flagsVector[index] == OPEN || flagsVector[index] == OPEN_AND_BOTTOM;
    }

    private int toFlatIndex(int i, int j) {
        return (i - 1) * N + (j - 1);
    }

    // DONE is site (row i, column j) full?
    public boolean isFull(int i, int j) {
        checkIndex(i);
        checkIndex(j);
        int flatIndex = toFlatIndex(i, j);
        return uf.connected(top, flatIndex);
    }

    // DONE does the system percolate?
    public boolean percolates() {
        return isPercolates;
    }

    // test client (optional)
    public static void main(String[] args) {

    }
}
