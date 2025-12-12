package kaushikd.intelligentprograms;

import java.util.List;
import java.util.stream.Collectors;

public class ProcessingStringsDemo {
    public static void main(String[] args) {
        var keywords
                = List.of("Main  ", "  class", "  Import  ", "  ");

        System.out.println("Before normalization...");
        keywords.forEach(System.out::println);

        List<String> normalizedKeywords =
                keywords.stream()
                    .map(k -> k.trim())
                    .filter(k -> !k.isEmpty())
                    .map(k -> k.toLowerCase())
                    .collect(Collectors.toList());

        System.out.println("After normalization...");
        normalizedKeywords.forEach(System.out::println);
    }
}

/*
OUTPUT
Before normalization...
Main
  class
  Import

After normalization...
main
class
import
 */
