package kaushik.java.hackerrank;

public class Test {
    private static boolean isPalindrome(String s, int lo, int hi) {
        int i = lo, j = hi;

        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }

    public static int palindromeIndex(String s) {
        int i = 0, j = s.length()-1;

        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                if (isPalindrome(s, i+1, j))    return i;
                if (isPalindrome(s, i, j-1))    return j;
            }
            else {
                i += 1;
                j -= 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(palindromeIndex("aaa"));
    }
}
