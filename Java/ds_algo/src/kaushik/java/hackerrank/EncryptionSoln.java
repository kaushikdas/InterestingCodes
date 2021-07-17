package kaushik.java.hackerrank;

// https://www.hackerrank.com/challenges/encryption/problem

/*
Solution sketch

EXAMPLE 1:

s = "haveaniceday"
  0  1  2  3  4  5  6  7  8  9  10 11
  h  a  v  e  a  n  i  c  e  d  a  y

L = 12 => m = 3, n = 4

  0 1 2 3 (n = 4)
  h a v e
  a n i c
  e d a y

         0  1  2  3  4  5  6  7  8  9  10 11
         h  a  v  e  a  n  i  c  e  d  a  y
  j = 0: ^           ^           ^           : k = 0, 4, 8  (, 12 >= L STOP)
                                                   h  a  e

  j = 1:    ^           ^           ^        : k = 1, 5, 9  (, 13 >= L STOP)
                                                   a  n  d

  j = 2:       ^           ^           ^     : k = 2, 6, 10 (, 14 >= L STOP)
                                                   v  i  a

  j = 3:          ^           ^           ^  : k = 3, 7, 11 (, 15 >= L STOP)
                                                   e  c  y

  j = 4 ( > n STOP)

EXAMPLE 2:

s = "feedthedoc"
  0  1  2  3  4  5  6  7  8  9
  f  e  e  d  t  h  e  d  o  g

L = 10 => m = 2, n = 3

  0 1 2 3 (n = 4)
  f e e d
  t h e d
  o g

         0  1  2  3  4  5  6  7  8  9
         f  e  e  d  t  h  e  d  o  g
  j = 0: ^           ^           ^           : k = 0, 4, 8  (, 12 >= L STOP)
                                                   f  t  o

  j = 1:    ^           ^           ^        : k = 1, 5, 9  (, 13 >= L STOP)
                                                   e  h  g

  j = 2:       ^           ^                 : k = 2, 6 (, 10 >= L STOP)
                                                   e  e

  j = 3:          ^           ^              : k = 3, 7(, 11 >= L STOP)
                                                   d  d

  j = 4 ( > n STOP)
*/

class EncryptionSoln {
    /*
     * Complete the 'encryption' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String encryption(String s) {
        // Extract valid charcters (a-z) from s
        StringBuffer src = new StringBuffer();
        int L = 0;              // # of valid characters
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != ' ') {     // not empty space
                src.append(c);
                L += 1;
            }
        }

        // find floor(sqrt(L)) & ceiling(sqrt(L))
        int n = 2;
        while (n*n < L) {
            n += 1;
        }
        // m <= sqrt(L) <= n

        StringBuffer result = new StringBuffer();
        for (int j = 0; j < n; j++) {
            for (int k = j; k < L; k += n) {
                result.append(src.charAt(k));
            }
            if (j != n-1) { // last set, no need to add space at end
                result.append(' ');
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String s = encryption("haveaniceday");
        assert "hae and via ecy".equals(s);
        System.out.println(s); // hae and via ecy
        s = encryption("feedthedog");
        assert "fto ehg ee dd".equals(s);
        System.out.println(s); // fto ehg ee dd
    }
}
