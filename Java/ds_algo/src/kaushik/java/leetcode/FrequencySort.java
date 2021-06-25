// https://leetcode.com/problems/sort-characters-by-frequency/

package kaushik.java.leetcode;

import java.util.Random;

class FrequencySort {
    final private int SZ = 128;

    private char chars[] = new char[SZ];
    private int freq[] = new int[SZ];
    private int N = 0;  // No. of characters in the string with freq != 0

    private void computeCharFreq(String s) {
        char c[] = new char[SZ];
        int f[] = new int[SZ];

        // Compute frequency if each character present in the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            f[ch] += 1;
            c[ch] = ch;
        }

        N = 0;
        // Copy the characters with non-zero frequency
        for (int i = 0; i < SZ; i++) {
            if (f[i] != 0) {
                chars[N] = c[i];
                freq[N] = f[i];
                N += 1;
            }
        }
    }

    // This will exchange frequency and corresponding character
    private void exchange(int i, int j) {
        int tf = 0;
        char tc = 0;

        tf = freq[i];
        tc = chars[i];

        // exchange frequencies
        freq[i] = freq[j];
        freq[j] = tf;

        // exchange characters
        chars[i] = chars[j];
        chars[j] = tc;
    }

    private int partition(int lo, int hi) {
        int x = freq[lo];
        int i = lo, j = lo + 1;     // i = lo - 1, j = lo   // If [hi] is pivot
        int tf = 0;
        char tc = 0;

        while (j <= hi) {           // while (j < hi) {     // If [hi] is pivot
            if (freq[j] > x) {
                // Exchange
                i += 1;
                exchange(i, j);
            }
            j++;
        }
                                    // i += 1;              // If [hi] is pivot
        exchange(i, lo);            // exchange(i, hi);     // If [hi] is pivot

        return i;
    }

    private void quicksort(int lo, int hi) {
        if (lo < hi) {
            int p = partition(lo, hi);
            quicksort(lo, p-1);
            quicksort(p+1, hi);
        }
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < freq[i]; j++) {
                sb.append(chars[i]);
            }
        }
        return sb.toString();
    }

    public String doIt(String s) {
        computeCharFreq(s);
        quicksort(0, N - 1);
        return toString();
    }

    public static void main(String[] args) {
        FrequencySort fs = new FrequencySort();

        String inputs[] = {"tree", "Aabb", "cccaaa"};
        String outputs[] = {"eert", "bbAa", "aaaccc"};

        for (int i = 0; i < inputs.length; i++) {
            String result = fs.doIt(inputs[i]);
            assert result.equals(outputs[i])
                    : String.format("Failed! Input: %s, Result: %s, Expected: %s"
                                    , inputs[i], result, outputs[i]);
        }
    }
}
