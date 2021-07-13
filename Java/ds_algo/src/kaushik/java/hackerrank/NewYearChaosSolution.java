package kaushik.java.hackerrank;

import java.util.Arrays;
import java.util.List;

// https://www.hackerrank.com/challenges/new-year-chaos/problem
class NewYearChaosSolution {
    /*
     * Complete the 'minimumBribes' function below.
     *
     * The function accepts INTEGER_ARRAY q as parameter.
     */
    public static void minimumBribes(List<Integer> q) {
        // Maintain a running window of 3 elements because
        // .. one can bribe at most two persons in front.
        // .. To start with, we are expecting 1, 2 and 3.
        int e1 = 1, e2 = 2, e3 = 3;

        int bribeCnt = 0;

        for (int e : q) {
            if (e == e1) {
                // expected person, just slide window by 1
                e1 = e2; e2 = e3; e3 += 1;
            }
            else if (e == e2) {
                // found expected 2nd person as the 1st
                bribeCnt += 1;
                e2 = e3; e3 += 1;   // slide only e2 and e3
            }
            else if (e == e3) {
                // found expected 3rd person as the 1st
                bribeCnt += 2;
                e3 += 1;
            }
            else {
                System.out.println("Too chaotic");
                return;
            }
        }
        System.out.println(bribeCnt);
    }

    public static void main(String[] args) {
        minimumBribes(Arrays.asList(2, 1, 5, 3, 4));    // 3
        minimumBribes(Arrays.asList(2, 5, 1, 3, 4));    // Too chaotic
    }
}
