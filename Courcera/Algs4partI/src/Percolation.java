
public class Percolation {
    private int N;
    private WeightedQuickUnionUF uf;
    private int top;
    private int bottom;

    private int[][] matrix;
    private int[] bottomRow;
    private int pointer;
    private boolean[] flags;
    private final static int CELL_OPEN = 1;
    private final static int CELL_CLOSED = 0;


    // create N-by-N grid, with all sites blocked
    public Percolation(int N) {
        if (N <= 0) throw new IllegalArgumentException();
        this.N = N;

        int countNodes = N * N + 2;

        this.uf = new WeightedQuickUnionUF(countNodes);
        this.top = countNodes - 2;
        this.bottom = countNodes - 1;

        this.matrix = new int[N][N];
        bottomRow = new int[N];
        flags = new boolean[N * N];
        for (int i = flags.length - N; i < flags.length; i++) {
            flags[i] = true;
        }
    }

    // DONE open site (row i, column j) if it is not open already
    public void open(int i, int j) {
        //System.out.println("COUTN: "+uf.count());
        checkIndex(i);
        checkIndex(j);

        if (!isOpen(i, j)) {

            matrix[i - 1][j - 1] = CELL_OPEN;

            int flatIdxCenter = toFlatIndex(i, j);

            if (i == 1) {
                uf.union(flatIdxCenter, this.top);
            }

            // TODO
            /*if (i == N) {
                uf.union(flatIdxCenter, this.bottom);
            }*/
            /*if (i == N) {
                bottomRow[pointer++] = j;
            }*/

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

                    conToBot = conToBot || flags[idd];
                   // System.out.println(flags[idd]);
                    //flags[idd] = false;
                    //System.out.println(flags[idd]);
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

            //System.out.println("**** *** *"+ flags[flatIdxCenter]+"===="+flatIdxCenter);
            int newRoot = uf.find(flatIdxCenter);
            flags[newRoot] = conToBot || flags[flatIdxCenter];


            /*for (int[] anIdx : idx) {

                int curI = anIdx[0];
                int curJ = anIdx[1];

                if (exists(curI, curJ) && isOpen(curI, curJ)) {
                    int flatIdx = toFlatIndex(curI, curJ);

                    int idd = uf.find(flatIdx);

                    flags[idd]= conToBot;

                    //flags[idd] = false;
                    //System.out.println(flags[idd]);
                }
            }*/


            if(!isPercolates&& uf.connected(flatIdxCenter,this.top)&&flags[newRoot] ) {
                isPercolates = true;
            }
           /* for (int col = 0; col < pointer&&!isPercolates; col++) {
                //int idx = matrix[N - 1][bottomRow[i]-1];
                int fidx = toFlatIndex(N, bottomRow[col] );
                if (uf.connected(fidx, this.top)) {
                    uf.union(this.bottom, fidx);
                    isPercolates = true;

                }
            }*/

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

        return (matrix[i - 1][j - 1] != CELL_CLOSED);
    }

    private int toFlatIndex(int i, int j) {
        return (i - 1) * N + (j - 1);
    }

    // DONE is site (row i, column j) full?
    public boolean isFull(int i, int j) {
        checkIndex(i);
        checkIndex(j);
        int flatIndex = toFlatIndex(i, j);
        //System.out.println(i+" "+ j+":"+ top+" "+ flatIndex);
        return uf.connected(top, flatIndex);
    }

    // DONE does the system percolate?
    public boolean percolates() {

        // Можно хранить список открытых элементов и безать только по ним
        /*for(int bitem =0; bitem < N;bitem++) {
            if(matrix[N-1][bitem]==CELL_OPEN_BOTTOM) {

                int fidx = toFlatIndex(N,bitem+1);
                if(uf.connected(fidx,this.top)) {
                    uf.union(this.bottom,fidx);
                }
            }
        }*/

        /*if (!isPercolates) {
            int idx = uf.find(top);
            System.out.println("^^^^" + idx);
            isPercolates = (N * N - N - 2) < idx && idx < (N * N - 2);
        }*/

        //System.out.format(">>> >>> %d %d %d\n", uf.find(top), uf.find(bottom), top);
        return isPercolates;   //uf.connected(top, bottom);   //isPercolates;  //
    }

    private boolean isPercolates = false;

    // test client (optional)
    public static void main(String[] args) {

    }
}
