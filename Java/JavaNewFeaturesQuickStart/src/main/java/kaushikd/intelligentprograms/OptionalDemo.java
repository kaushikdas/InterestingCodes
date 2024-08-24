package kaushikd.intelligentprograms;

import java.util.Optional;

public class OptionalDemo {
    public static void main(String[] args) {
        Optional<Object> emptyOpt = Optional.empty();
        Optional<String> nonEmptyOpt = Optional.of("Name: Kaushik");

        // Without using orElse
        if (nonEmptyOpt.isPresent()) {
            System.out.println("Value: " + nonEmptyOpt.get());
        }
        else {
            System.out.println("Empty object");
        }

        // Using orElse
        System.out.println("Value: " + emptyOpt.orElse(""));
        System.out.println("Value: " + nonEmptyOpt.orElse(""));
    }
}
