package kaushik.java.hackerrank;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

// https://www.hackerrank.com/challenges/crush/problem
class ArrayManipulationSolution {
    /*
     * Complete the 'arrayManipulation' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. 2D_INTEGER_ARRAY queries
     */
    public static long arrayManipulation(int n, List<List<Integer>> queries) {
        // Write your code here
        int[] arr = new int[n+1]; // 1 indexed array

        for (List<Integer> q : queries) {
            int a = q.get(0), b = q.get(1), k = q.get(2);
            // (a, b, k) -> values between arr[a..b] are incaremented by k
            // .. Instead of actually incrementing all elements arr[a..b]
            // .. just incremenet arr[a] by k and decrement arr[b+1] by k:
            // ..
            // ..            +k                   -k
            // ..    +-----+----+---------------+----+------+
            // ..    | ... |    |   ....        |    | ...  |
            // ..    +-----+----+---------------+----+------+
            // ..             a                    b
            // .. This indicates that all elements before index a and after
            // .. index b are less than [a..b] by k. So that when we calculate
            // .. the value at an index using CUMULATIVE sum till that index
            // .. we get the correct value.
            arr[a] += k;
            if ((b+1) <= n) {
                arr[b+1] -= k;
            }
        }

        long max = Long.MIN_VALUE, sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += arr[i];
            if (sum > max) {
                max = sum;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        List<List<Integer>> queries = new ArrayList<>();
        queries.add(Arrays.asList(1, 2, 100));
        queries.add(Arrays.asList(2, 5, 100));
        queries.add(Arrays.asList(3, 4, 100));
        long max = arrayManipulation(5, queries);
        System.out.println(max);
        assert max == 200 : "Failed";
    }
}
