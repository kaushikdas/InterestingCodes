package kaushikd.intelligentprograms;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class PalindromeListChecker {
    private static class Node<T> {
        T item;
        Node<T> next;
    }

    private static class Queue<E> implements Iterable<E> {
        private Node<E> front;
        private Node<E> rear;
        private int N;

        public int size() {
            return N;
        }

        public boolean isEmpty() {
            return (front == null);
        }

        public void enqueue(E item) {
            Node<E> node = new Node<E>();
            node.item = item;
            if (front == null) {
                front = rear = node;
            }
            else {
                rear.next = node;
                rear = node;
            }
            N++;
        }

        public E dequeue() {
            if (front == null) {
                throw new NoSuchElementException();
            }

            E item = front.item;
            front = front.next;
            if (front == null) {
                rear = null;
            }
            N--;
            return item;
        }

        @Override
        public Iterator<E> iterator() {
            return new QueueIterator();
        }

        private class QueueIterator implements Iterator<E> {
            Node<E> current = front;

            @Override
            public boolean hasNext() {
                return (current != null);
            }

            @Override
            public E next() {
                E item = current.item;
                current = current.next;
                return item;
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        }
    }

    private static class Stack<E> implements Iterable<E> {
        private static int CAPACITY = 8;
        private E items[];
        private int N;

        public Stack() {
            items = (E []) new Object[CAPACITY];
            N = 0;
        }

        public int size() {
            return N;
        }

        public void push(E item) {
            if (N == items.length) {
                items = Arrays.copyOf(items, N << 1);
            }
            items[N++] = item;
        }

        public E pop() {
            E item = items[--N];
            items[N + 1] = null;
            if (N > 0 && N == items.length/4) {
                items = Arrays.copyOf(items, items.length >> 1);
            }
            return item;
        }

        @Override
        public Iterator<E> iterator() {
            return new StackIterator();
        }

        private class StackIterator implements Iterator<E> {
            private int current = N - 1;

            @Override
            public boolean hasNext() {
                return (current >= 0);
            }

            @Override
            public E next() {
                return items[current--];
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        }
    }

    public static void main(String[] args) {
        Queue<Character> ltr = new Queue<>();
        Stack<Character> rtl = new Stack<>();

        String ignore = " ,.?:-!";
        for (String s : args) {
            for (int i = 0; i < s.length(); i++) {
                Character c = Character.toLowerCase(s.charAt(i));
                if (ignore.indexOf(c) == -1) {
                    ltr.enqueue(c);
                    rtl.push(c);
                }
            }
        }

        assert ltr.size() == rtl.size();

        while (!ltr.isEmpty()) {
            if (ltr.dequeue() != rtl.pop()) {
                System.out.println("NOT PALINDROME");
                return;
            }
        }
        System.out.println("PALINDROME");
    }
}
