import java.util.Arrays;
import java.util.stream.Collectors;

public class ReverseStringWords {
    public String reverseWordsV1(String s) {
        String words[] = s.trim().split("[ ]+");
        int i = 0;
        StringBuilder sb = new StringBuilder();
        //Arrays.stream(words).filter(w -> (!"".equals(w.trim()))).forEach(w -> System.out.println(w.length()));
        System.out.println(words.length);
        for (int k = words.length - 1; k > 0 ; k--) {
            sb.append(words[k]).append(" ");
        }
        sb.append(words[0]);
        return sb.toString();
    }

    private void reverseWord(char t[], int start, int end) {
        int lo = start, hi = end;
        while (lo < hi) {
            char x = t[lo];
            t[lo] = t[hi];
            t[hi] = x;
            lo++; hi--;
        }
    }

    public String reverseWordsV2(String s) {
        char x[] = s.toCharArray();
        char t[] = new char[x.length];
        boolean isInsideWord = false;
        int j = 0, startOfWord = 0, endOfWord = 0;
        char c = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            c = x[i];
            if (c == ' ') {
                if (isInsideWord) {
                    endOfWord = j - 1;
                    t[j++] = ' ';
                    reverseWord(t, startOfWord, endOfWord);
                }
                isInsideWord = false;
            }
            else {
                if (!isInsideWord) {
                    startOfWord = j;
                    isInsideWord = true;
                }
                t[j++] = c;
            }
        }

        if (isInsideWord) {
            endOfWord = j - 1;
            reverseWord(t, startOfWord, endOfWord);
        }

        isInsideWord = false;
        String result = new String(t, 0, endOfWord + 1);
        System.out.println(">" + result + "<");
        return result;
    }

    public String reverseWordsV3(String s) {
        char t[] = s.toCharArray();
        reverseWord(t, 0, t.length - 1);
        boolean isInsideWord = false;
        int j = 0, startOfWord = 0, endOfWord = 0;
        char c = 0;
        for (int i = 0; i < s.length(); i++) {
            c = t[i];
            if (c == ' ') {
                if (isInsideWord) {
                    endOfWord = j - 1;
                    t[j++] = ' ';
                    reverseWord(t, startOfWord, endOfWord);
                }
                isInsideWord = false;
            }
            else {
                if (!isInsideWord) {
                    startOfWord = j;
                    isInsideWord = true;
                }
                t[j++] = c;
            }
        }

        if (isInsideWord) {
            endOfWord = j - 1;
            reverseWord(t, startOfWord, endOfWord);
        }

        isInsideWord = false;
        String result = new String(t, 0, endOfWord + 1);
        System.out.println(">" + result + "<");
        return result;
    }

    public static void main(String[] args) {
        ReverseStringWords ob = new ReverseStringWords();
        ob.reverseWordsV1("      hello       world           ");
        ob.reverseWordsV2("the sky is blue");
        ob.reverseWordsV2("  hello world  ");
        ob.reverseWordsV3("the sky is blue");
        ob.reverseWordsV3("  hello world  ");
    }
}
