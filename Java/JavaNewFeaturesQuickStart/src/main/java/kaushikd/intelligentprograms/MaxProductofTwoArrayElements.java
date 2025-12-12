package kaushikd.intelligentprograms;

import java.util.Arrays;

public class MaxProductofTwoArrayElements {
    public static int maxProduct(int[] a) {
        if (a.length < 2) {
            System.err.println("Not enough elements in the array!");
            return Integer.MIN_VALUE;
        }

        /*
         min1 is the minimum element in the array, min1 <= min2
         max1 is the maximum element in the array, max1 >= max2
         */

        int min1 = a[0], min2 = a[1];
        if (a[0] > a[1]) {
            min1 = a[1]; min2 = a[0];
        }
        int max1 = a[0], max2 = a[2];
        if (a[0] < a[1]) {
            max1 = a[1]; max2 = a[0];
        }

        // In this loop we will ensure the invariants that
        // . 1 min1, min2 are 1st & 2nd min. in the array, respectively
        // . 2 max1, max2 are 1st & 2nd max. in the array, respectively
        for (int i = 2; i < a.length; i++) {
            // Ensure invariant for min1 & min2
            if (a[i] < min1) {
                min2 = min1; min1 = a[i];
            }
            else if (a[i] < min2) {
                min2 = a[i];
            }

            // Ensure invariant for max1 & max2
            if (a[i] > max1) {
                max2 = max1; max1 = a[i];
            }
            else if (a[i] > max2) {
                max2 = a[i];
            }
        }

        int product1 = min1 * min2, product2 = max1 * max2;
        if (product1 > product2)    return product1;
        else                        return product2;
    }

    public static void main(String[] args) {
        int[] a1 = {2, 8, 1, -5, 5, 8};
        int[] a2 = {-5, -3, 1, -2, 0, -6};
        int[] a3 = {2, 4, 9, 6, 3, 10};

        System.out.println("Max product of " + Arrays.toString(a1)
                            + " = " + maxProduct(a1));
        System.out.println("Max product of " + Arrays.toString(a2)
                + " = " + maxProduct(a2));
        System.out.println("Max product of " + Arrays.toString(a3)
                + " = " + maxProduct(a3));
    }
}

/*
OUTPUT
Max product of [2, 8, 1, -5, 5, 8] = 64
Max product of [-5, -3, 1, -2, 0, -6] = 30
Max product of [2, 4, 9, 6, 3, 10] = 90
 */