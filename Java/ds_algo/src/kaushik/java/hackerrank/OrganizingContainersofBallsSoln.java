package kaushik.java.hackerrank;

import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
class OrganizingContainersofBallsSoln {
    /*
     * Complete the 'organizingContainers' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts 2D_INTEGER_ARRAY container as parameter.
     */

    public static String organizingContainers(List<List<Integer>> container) {
        // Write your code here
        int n = container.size();   // n = # of colours = # of containers
        long[] col = new long[n];   // col[i] = # of balls of colour i
        long[] cap = new long[n];   // cap[i] = # of balls in container[i]

        int i = 0, j = 0;

        for (i = 0; i < n; i++) {
            List<Integer> box = container.get(i);
            long size = 0;

            for (j = 0; j < n; j++) {
                int f = box.get(j); // f = no of jth colour balls in ith box
                col[j] += f;        // increment count of jth color by f
                size += f;          // increment size by f
            }
            cap[i] = size;          // # of balls in ith box
        }

        String result = "Possible";
        for (i = 0; i < n; i++) {
            long size = cap[i];
            for (j = i; j < n; j++) {
                if (size == col[j]) {
                    // ith container can exactly fit all balls of color j
                    // exchange the frequency of colour i with that of
                    // colour j. Note, j >= i and col[i] != size,
                    // col[i] != size, ... col[j-1] != size BUT
                    // col[j] == size.
                    // We exchange, col[j] with col[i] because next
                    // in the next iteration search of a colour
                    // freq will start from next i (i.e., i+1).
                    // Therefore col[0...i] stores the freq of colours
                    // that are already settled in box[0...i].
                    long temp = col[j];
                    col[j] = col[i];
                    col[i] = temp;
                    break;  // This break is important
                }
            }
            if (j == n) {
                // No colors found that has freq same as ith box cap
                result = "Impossible";
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> container = new ArrayList<>();
        container.add(Arrays.asList(1, 1));
        container.add(Arrays.asList(1, 1));
        System.out.println(organizingContainers(container));    // Possible

        container = new ArrayList<>();
        container.add(Arrays.asList(0, 2));
        container.add(Arrays.asList(1, 1));
        System.out.println(organizingContainers(container));    // Impossible
    }
}
