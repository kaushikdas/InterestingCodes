package kaushik.java.hackerrank;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.HashSet;

// https://www.hackerrank.com/challenges/pairs/problem
public class PairsWithGivenDifference {
    /*
     * Complete the 'pairs' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER k
     *  2. INTEGER_ARRAY arr
     */

    public static int getPairsUsing2Ptr(int k, List<Integer> arr) {
        // Write your code here
        Integer[] A = new Integer[arr.size()];
        A = arr.toArray(A);
        Arrays.sort(A);

        int i = 0, j = 1, result = 0;
        while (i < A.length) {
            while ((j < A.length) && (A[j] < A[i]+k)) {
                j += 1;
            }
            if ((j < A.length) && (A[j] == A[i]+k)) {
                result += 1;
            }
            i += 1;
            if (j <= i) {
                j = i + 1;
            }
        }

        return result;
    }

    public static int getPairsUsingHash(int k, List<Integer> arr) {
        HashSet<Integer> map = new HashSet<>();
        int result = 0;
        Integer[] A = new Integer[arr.size()];
        arr.toArray(A);
        Arrays.sort(A);

        for (Integer e : A) {
            if (map.contains(e)) {
                result += 1;
            }
            map.add(e+k);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] inputDiff = {2, 1, 2};
        int[] expectedResult = {3, 0, 5};
        List<List<Integer>> lists = new ArrayList<>();
        lists.add(Arrays.asList(1, 5, 3, 4, 2));
        lists.add(Arrays.asList(363374326, 364147530, 61825163,
                                1073065718, 1281246024, 1399469912,
                                428047635, 491595254, 879792181,
                                1069262793));
        lists.add(Arrays.asList(1, 3, 5, 8, 6, 4, 2));

        int result = 0, i = 0;
        String s;
        for (int k : inputDiff) {
            s = "[" + i + "] Result: ";
            result = getPairsUsing2Ptr(k, lists.get(i));
            assert result == expectedResult[i];
            s += "Two pointer - " + result;

            result = getPairsUsingHash(k, lists.get(i));
            assert result == expectedResult[i];
            s += ", Hash - " + result;
            System.out.println(s);
            i++;
        }
    }
}
