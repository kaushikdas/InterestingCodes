package kaushik.java.hackerrank;

import java.util.HashMap;

public class SherlockAndAnagrams {
  public static int sherlockAndAnagrams(String s) {
    String in = s.toLowerCase(); // convert to lower case (just in case...)

    int cnt = 0;

    for (int len = 1; len < s.length(); len++) {
      // Make a dict for in[0 ... sz-1]

      for (int i = 0; i < (s.length() - len + 1); i++) {
        HashMap<Character, Integer> dict = new HashMap<>();
        for (int k = i; k < (i + len); k++) {
          dict.merge(s.charAt(k), 1, (oldVal, newVal) -> oldVal + newVal);
        }
        for (int j = i + 1; j < (s.length() - len + 1); j++) {
          HashMap<Character, Integer> pairDict = new HashMap<>();
          for (int k = j; k < (j + len); k++) {
            pairDict.merge(s.charAt(k), 1, (oldVal, newVal) -> oldVal + newVal);
          }
          if (dict.equals(pairDict)) {
            cnt++;
          }
        }
      }
    }

    return cnt;
  }

  public static void main(String[] args) {
    System.out.println(sherlockAndAnagrams("abcd"));
  }
}
