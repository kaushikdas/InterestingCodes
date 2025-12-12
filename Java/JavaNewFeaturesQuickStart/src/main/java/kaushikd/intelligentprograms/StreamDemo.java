package kaushikd.intelligentprograms;

import java.util.Arrays;
import java.util.List;
import java.util.function.Supplier;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StreamDemo {
    public static void main(String[] args) {
        // Create a stream - Stream.of()
        Stream<String> nameStream
                = Stream.of("einstein", "newton", "joule", "bell");
        
        // Stream from other collections
        
        // Array - use Arrays.stream()
        String[] lengthUnits = new String[] {"meter", "foot", "centimeter"};
        Stream<String> arrayStream = Arrays.stream(lengthUnits);

        // List - use <list_name>.stream()
        List<String> massUnits = List.of("kilogram", "pound", "gram");
        Stream<String> listStream = massUnits.stream();

        // For loop
        arrayStream.forEach(System.out::println);
            // After this forEach on arrayStream we cannot use
            // ... arrayStream anymore because the stream arrayStream
            // ... gets consumed and closed because of applying the
            // ... terminal operation forEach, if we still try to use
            // ... Stream will throw IllegalStateException - streams
            // ... are for single time use
            // ... SOLUTION: Create a new Stream each time we need one
            //          We shall use Supplier interface

        Supplier<Stream<String>> arrayStreamSupplier
                = () -> Arrays.stream(lengthUnits);
        Supplier<Stream<String>> listStreamSupplier
                = () -> massUnits.stream();

        boolean isAllGrams = listStream
                                .allMatch(massUnit
                                        -> massUnit.endsWith("gram"));
        boolean hasFoot = arrayStreamSupplier.get()
                                .anyMatch(lengthUnit
                                        -> lengthUnit.equals("foot"));
        System.out.println("isAllGrams: " + isAllGrams +
                           ", hasFoot: " + hasFoot);

        // Filter - select only specific items
        Stream<String> meters = arrayStreamSupplier.get()
                                    .filter(item
                                            -> item.endsWith("meter"));

        // Map - operate on each item
        List<String> massUnitsUppercase
                = listStreamSupplier.get()
                                    .map(item -> item.toUpperCase())
                                    .collect(Collectors.toList());
            // Here we are collecting the map result as a collection
        massUnitsUppercase.forEach(System.out::println);
    }
}

/*
OUTPUT
meter
foot
centimeter
isAllGrams: false, hasFoot: true
KILOGRAM
POUND
GRAM
 */