package kaushikd.intelligentprograms;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.function.Consumer;

public class ListTraversal {
    public static void main(String[] args) {
        List<String> mainMethod
                = List.of("public", "static", "void", "main");
        List<String> mainMethodReversed = new ReversedList();
        mainMethodReversed.addAll(mainMethod);

        System.out.println("Reversed signature...");
        mainMethodReversed.forEach(s -> System.out.print(s + " "));
        System.out.println();

        // But stream will not produce this
        System.out.println("But stream will not produce this...");
        mainMethodReversed.stream()
                .forEach(s -> System.out.print(s + " "));
        System.out.println();
    }
}

class ReversedList extends ArrayList<String> {

    @Override
    public Iterator<String> iterator() {
        int startIndex = this.size() - 1;
        List<String> list = this;

        return new Iterator<String>() {
            private int index = startIndex;

            @Override
            public boolean hasNext() {
                return index >= 0;
            }

            @Override
            public String next() {
                String s = list.get(index);
                --index;
                return s;
            }
        };
    }

    //@Override
    public void forEach(Consumer<? super String> action) {
        for (var s : this)
            action.accept(s);
    }
}

class ReverseIterator implements Iterator<String> {

    int index = 0;
    List<String> list;

    ReverseIterator(List<String> list) {
        this.list = list;
        index = list.size() - 1;
    }

    @Override
    public boolean hasNext() {
        return index >= 0;
    }

    @Override
    public String next() {
        String s = list.get(index--);
        return s;
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
