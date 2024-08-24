package kaushikd.intelligentprograms;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class GenericLinkedList<Item> implements Iterable<Item>{
    private Node<Item> head = null;   // list head
    private Node<Item> tail = null;   // list tail
    private int N = 0;          // number of nodes in the list

    private static class Node<T> {
        T item;
        Node<T> next;
    }

    public void add(Item item) {
        Node<Item> node = new Node<Item>();
        node.item = item;
        node.next = null;
        if (head == null) {
            head = tail = node;
        }
        else {
            tail.next = node;
            tail = node;
        }
        N++;
    }

    public void delete(int index) {
        if (index < 0 || index >= N) {
            return;
        }
        Node<Item> node = head, prev = null;
        int i = 0;
        while (i != index) {
            prev = node;
            node = node.next;
            i++;
        }
        if (node == head) {
            head = head.next;
            if (head == null) {
                tail = null;
            }
        }
        else if (node == tail) {
            tail = prev;
        }
        else {
            prev.next = node.next;
        }
        N--;
    }

    public void deleteMiddle() {
        if (N == 0) return;
        delete(N >> 1);
    }

    public Iterator<Item> iterator() {
        return new LinkedListIterator(head);
    }

    private class LinkedListIterator implements Iterator<Item> {
        private Node<Item> current;

        public LinkedListIterator(Node head) {
            current = head;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            if (current == null) {
                throw new NoSuchElementException();
            }
            Item item = current.item;
            current = current.next;
            return item;
        }

        //@Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
        GenericLinkedList<String> ll = new GenericLinkedList<>();

        ll.add("one"); ll.add("two"); ll.add("three");
        System.out.println("Initial list...");
        for (String s : ll) {
            System.out.print(s + ", ");
        }
        System.out.println();

        ll.deleteMiddle();
        System.out.println("After delete middle 1 ...");
        for (String s : ll) {
            System.out.print(s + " -> ");
        }
        System.out.println();

        ll.add("four"); ll.add("five");
        System.out.println("After adding 2 more items ...");
        for (String s : ll) {
            System.out.print(s + " -> ");
        }
        System.out.println();

        ll.deleteMiddle();
        System.out.println("After delete middle 2 ...");
        for (String s : ll) {
            System.out.print(s + " -> ");
        }
        System.out.println();
    }
}

/*
OUTPUT
Initial list...
one, two, three,
After delete middle 1 ...
one -> three ->
After adding 2 more items ...
one -> three -> four -> five ->
After delete middle 2 ...
one -> three -> five ->
 */