/**
 * Created by igor on 01.07.2015.
 */
public class PercolationStats {

    private double mean = Double.NaN;
    private double stddev = Double.NaN;
    private int T;
    private double[] xt;

    /**
     * TODO perform T independent experiments on an N-by-N grid
     *
     * @param N
     * @param T
     */
    public PercolationStats(int N, int T) {
        validate(N);
        validate(T);
        this.T = T;

        xt = new double[T];

        for (int i = 0; i < T; i++) {
            int x = 0;
            Percolation percolation = new Percolation(N);
            while (!percolation.percolates()) {
                x++;

                int row = StdRandom.uniform(1, N + 1);
                int col = StdRandom.uniform(1, N + 1);
                while (percolation.isOpen(row, col)) {
                    row = StdRandom.uniform(1, N + 1);
                    col = StdRandom.uniform(1, N + 1);
                }
                percolation.open(row, col);
            }

            xt[i] = ((double) x) / (double) (N * N);
        }
    }

    private void validate(int N) {
        if (N <= 0) throw new java.lang.IllegalArgumentException("args can't be <= 0");
    }

    /**
     * sample mean of percolation threshold
     *
     * @return
     */
    public double mean() {

        if (Double.isNaN(mean)) {
            double sum = 0;
            for (int i = 0; i < T; i++) {
                sum += xt[i];
            }


            mean = sum / T;
        }


        return mean;
    }

    /**
     * sample standard deviation of percolation threshold
     *
     * @return
     */
    public double stddev() {
        if (Double.isNaN(stddev)) {
            double sum = 0;
            for (int i = 0; i < T; i++) {
                sum += (xt[i] - mean()) * (xt[i] - mean());
            }
            stddev = Math.sqrt(sum / (T - 1));
        }

        return stddev;
    }

    /**
     * TODO low  endpoint of 95% confidence interval
     *
     * @return
     */
    public double confidenceLo() {
        return mean() - 1.96 * stddev() / Math.sqrt(T);
    }

    /**
     * TODO high endpoint of 95% confidence interval
     *
     * @return
     */
    public double confidenceHi() {
        return mean() + 1.96 * stddev() / Math.sqrt(T);
    }

    /**
     * test client (described below)
     *
     * @param args
     */
    public static void main(String[] args) {

        if (args.length < 2) throw new IllegalArgumentException("wait two numbers");
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);

        PercolationStats stats = new PercolationStats(N, T);
        System.out.println("mean: " + stats.mean());
        System.out.println("stddve: " + stats.stddev());
        System.out.println("95% confidence interval: " + stats.confidenceLo() + " " + stats.confidenceHi());
    }
}
