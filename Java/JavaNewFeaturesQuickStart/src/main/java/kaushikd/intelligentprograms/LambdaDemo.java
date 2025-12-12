package kaushikd.intelligentprograms;

import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.IntPredicate;
import java.util.function.Supplier;

public class LambdaDemo {
    public static void main(String[] args) {
        ArrayList<String> ubuntuVersions = new ArrayList<>();
        ubuntuVersions.add("Groovy Gorilla");
        ubuntuVersions.add("Focal Fossa");
        ubuntuVersions.add("Bionic Beaver");
        ubuntuVersions.add("Xenial Xerus");
        ubuntuVersions.add("Trusty Tahr");

        // common use of lambda
        ubuntuVersions.forEach(v -> System.out.println(v));

        // Consumer - takes input(s) but returns nothing
        Consumer<String> printVersion = v -> System.out.println(v);
        ubuntuVersions.forEach(printVersion);

        // Function - takes input(s) and returns value
        Function<String, Integer> makeLowerCase = s -> s.length();
        // Invoke Function using apply
        System.out.println(makeLowerCase.apply("Trusty Tahr"));

        // Predicate - takes input and return boolean
        IntPredicate isMultipleOf3 = x -> x % 3 == 0;
        // Invoke predicate using test method
        System.out.println(isMultipleOf3.test(15));

        // Supplier - takes no inputs but returns value
        Supplier<Double> randomValueBelow100
                = () -> Math.random() * 100;
        // Invoke the Supplier using get method
        System.out.println(randomValueBelow100.get());

    }
}

/*
OUTPUT
Groovy Gorilla
Focal Fossa
Bionic Beaver
Xenial Xerus
Trusty Tahr
Groovy Gorilla
Focal Fossa
Bionic Beaver
Xenial Xerus
Trusty Tahr
11
true
57.616166838399415
 */
