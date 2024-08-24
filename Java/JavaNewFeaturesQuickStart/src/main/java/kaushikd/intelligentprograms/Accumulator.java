package kaushikd.intelligentprograms;

public class Accumulator {
    double s;
    double m;
    int N;

    public void addNumber(double x) {
        N++;
        s += 1.0 * (N - 1) / N * (x - m) * (x - m);
        m += (x - m) / N;
    }
    public double mean() {
        return m;
    }
    public double var() {
        return s / (N - 1);
    }
    public double stddev() {
        return Math.sqrt(var());
    }

    @Override
    public String toString() {
        return "Accumulator (" + N + " numbers): "
                + "mu = " + String.format("%7.5f", m)
                + ", sigma = " + String.format("%7.5f", stddev());
    }

    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);

        Accumulator ac = new Accumulator();

        for (int i = 0; i < T; i++) {
            ac.addNumber(Math.random());
        }
        System.out.println(ac);
    }
}

/*
%java Accumulator 100
Accumulator (100 numbers): mu = 0.50470, sigma = 0.28573

%java Accumulator 200
Accumulator (200 numbers): mu = 0.46953, sigma = 0.29920

%java Accumulator 400
Accumulator (400 numbers): mu = 0.50910, sigma = 0.28568
 */
