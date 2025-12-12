package kaushikd.intelligentprograms;

import java.util.stream.IntStream;

public class PalindromeCheckerStream {
    public static boolean isPalindrome(String s) {
        String t = s.toLowerCase();
        int l = t.length();

        return IntStream.range(0, l/2)
                .allMatch(i -> t.charAt(i) == t.charAt(l - 1 - i));
    }

    public static void main(String[] args) {
        System.out.println("isPalindrome(\"civic\"): "
                + isPalindrome("civic"));
        System.out.println("isPalindrome(\"Racecar\"): "
                + isPalindrome("civic"));
        System.out.println("isPalindrome(\"02022020\"): "
                + isPalindrome("civic"));
        System.out.println("isPalindrome(\"Wi-Fi\"): "
                + isPalindrome("Wi-Fi"));
    }
}
