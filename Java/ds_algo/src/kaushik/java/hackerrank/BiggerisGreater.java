package kaushik.java.hackerrank;

// https://www.hackerrank.com/challenges/bigger-is-greater/problem

/**
 * Example: a c b d g l l h h e e a
 *
 *     Start with last two chars:               a c b d g l l h h e e a
 *     and keep moving left till                            ^ ^
 *     previous char is not less
 *                                              a c b d g l l h h e e a
 *                                                      ^ ^
 *     For the string that comes
 *     lexicographically next at the
 *     position g the char from
 *     (l l h h e e a) that is just
 *     greater than g will come and
 *     next to that (l l h g e e a)
 *     will appear in sorted order
 *
 *     Find the last character in                       l l h h e e a
 *     that is just greater than g                              *
 *
 *     Swap that with g                         a c b d h l l h g e e a
 *                                                      ^       *
 *     l l h g e e a is sorted in
 *     descending order
 *
 *     Next lexicographic string is             a c b d h a e e g h l l
 *     a c b d h + reversed(l l h g e e a)
 */
class BiggerisGreater {
    /*
     * Complete the 'biggerIsGreater' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING w as parameter.
     */

    public static String biggerIsGreater(String w) {
        // Write your code here
        char[] s = w.toCharArray();
        int L = w.length();

        int j = L-1, i = j-1;       // start from the last char
        while (i >= 0) {            // and keeping moving left
            if (s[j] <= s[i]) {     // if previous char is greater
                j = i;
                i -= 1;
            }
            else
                break;
        }
        if (i < 0)
            return "no answer";

        // s[i] < s[j] >= s[j+1] >= S[j+2] >= ... >= s[L-1]
        // find the char from s[j..L-1] that is just > s[i]
        int k = j;
        while (k < L) {
            if (s[k] > s[i])
                k += 1;
            else
                break;
        }
        // s[k-1] is just > s[i]
        char temp = s[i];           // swap s[k-1] & s[i]
        s[i] = s[k-1];
        s[k-1] = temp;

        // since s[i] (now s[k-1]) was < s[j], after the swap
        // also s[j] >= s[j+1] >= S[j+2] >= ... >= s[L-1]
        // reverse s[j]..s[L-1]
        int lo = j, hi = L-1;
        while (lo < hi) {
            temp = s[lo];           // swap s[lo] & s[hi]
            s[lo++] = s[hi];
            s[hi--] = temp;
        }

        return new String(s);
    }

    public static void main(String[] args) {
        String[] inputs = {"ab", "bb", "hefg", "dhck", "dkhc", "lmno",
                           "dcba", "dcbb", "abdc", "abcd", "fedcbabcd"};
        String[] outputs = {"ba", "no answer", "hegf", "dhkc", "hcdk",
                            "lmon", "no answer", "no answer", "acbd",
                            "abdc", "fedcbabdc"};

        int i = 0;
        for (String w : inputs) {
            assert outputs[i++].equals(biggerIsGreater(w));
        }
        System.out.println("Done!");
    }
}
