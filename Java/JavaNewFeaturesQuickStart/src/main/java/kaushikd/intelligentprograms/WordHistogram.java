package kaushikd.intelligentprograms;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class WordHistogram {
    static final List stopWords = List.of("the", "a", "of", "an", "it", "and"
            , "but", "is", "are", "of", "on", "am", "to", "was", "were", "in"
            , "that", "i", "your", "you", "his", "her", "their", "be",
            "they", "at", "me");
    static final String SEPARATORS = "[ \\n\\t\\r(){}.,;:?!]";

    public static void generate(String input) {
        Map<String, Integer> wordMap = new HashMap<>();
        String normalizedString = input.toLowerCase();
        String[] words = normalizedString.split(SEPARATORS);

        List<String> wordList = Stream.of(words)
                                    .filter(w -> w.length() != 0 && !stopWords.contains(w))
                                    .collect(Collectors.toList());
        wordList.forEach(w -> {
            wordMap.compute(w, (k, v) -> (v == null)? 1 : v + 1);
        });
        for (String k : wordMap.keySet()) {
            System.out.println(k + ": " + wordMap.get(k).toString());
        }
    }

    public static void main(String[] args) {
        String testString = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
        generate(testString);
    }
}
