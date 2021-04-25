package kaushik.java.epiAziz;

import java.util.Iterator;
import java.util.Random;

public class ZipSinglyLinkedList {
    private static class SinglyLinkedList<T> implements Iterable<T> {
        class Node {
            T item;
            Node next;
        }

        Node head;  // list head
        int sz;

        public void add(T item) {
            // add item to head;
            Node n = new Node();
            n.item = item;
            n.next = head;
            head = n;
            sz++;
        }

        public int size() {
            return sz;
        }

        private Node reverse(Node first) {
            Node rlh = null, temp = first;
            while (temp != null) {
                Node n = temp;
                temp = temp.next;   // Remove n from original list
                n.next = rlh;       // ... and add to the head
                rlh = n;            // ... of the reverse list
            }
            return rlh;
        }

        public void reverse() {
            head = reverse(head);
        }

        /*
         * If The list has N nodes (1) -> (2) -> (3) -> ... -> (N-1) -> (N)
         * nodes from the back two inserted between the nodes in the front
         *   N will go between 1 & 2
         *   N-1 will go between 2 & 3
         *   N-2 will go between 3 & 4 etc.
         * After zipping the above list will become like
         *  (1) -> (N) -> (2) -> (N-1) -> (3) -> ...
         * If N = 2M+1 (odd), then M nodes from the end will go between
         *  M+1 nodes in the beginning.
         * If N = 2M (even), then M-1 nodes from end will go between
         * M nodes
         * IDEA
         *   Divide the list in two halves - left half [1 ... median node(s)]
         *   and right half [median nodes(s) + 1 ... N]
         *   Reverse the right half and insert nodes 1by1 from the reversed right
         *   half between the nodes in left half
         */
        public void zip() {
            if (sz < 3) return;

            Node fast = head, slow = head;
            // reach the median node
            while (fast != null && fast.next != null) {
                fast = fast.next.next;
                slow = slow.next;
            }
            // slow points to the median node, if there are even number of nodes
            // ...slow will point to tne 2nd median node
            Node rightHalfHead = slow.next;
            slow.next = null;   // this forms the left half [head...slow]
            rightHalfHead = reverse(rightHalfHead);
            Node leftHalfHead = head;
            while (rightHalfHead != null) {
                Node n = rightHalfHead;
                rightHalfHead = rightHalfHead.next;
                // add n between leftHalfHead and its next
                n.next = leftHalfHead.next;
                leftHalfHead.next = n;
                leftHalfHead = n.next;
            }
        }

        @Override
        public Iterator<T> iterator() {
            return new SinglyLinkedListIterator(head);
        }

        private class SinglyLinkedListIterator implements Iterator<T> {
            Node current;

            public SinglyLinkedListIterator(Node head) { current = head; }

            @Override
            public boolean hasNext() { return (current != null); }

            @Override
            public T next() {
                T v = null;
                if (current != null) {
                    v = current.item;
                    current = current.next;
                }
                return v;
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            int N = random.nextInt(15) + 1;
            System.out.println("TEST CASE: " + (i + 1) + ", list size: " + N);
            SinglyLinkedList<Integer> sll = new SinglyLinkedList();
            for (int j = 0; j < N; j++) {
                sll.add(random.nextInt(25));
            }
            System.out.printf("Original list content:%n\t[ ");
            for (int n : sll) {
                System.out.print(n + " ");
            }
            System.out.println("]");
            sll.zip();
            System.out.printf("Zipped list content:%n\t[ ");
            for (int n : sll) {
                System.out.print(n + " ");
            }
            System.out.println("]");
        }
    }
}

/*
SAMPLE OUTPUT
TEST CASE: 1, list size: 7
Original list content:
	[ 1 24 3 12 11 3 12 ]
Zipped list content:
	[ 1 12 24 3 3 11 12 ]
TEST CASE: 2, list size: 12
Original list content:
	[ 12 4 9 17 1 9 14 16 0 10 12 21 ]
Zipped list content:
	[ 12 21 4 12 9 10 17 0 1 16 9 14 ]
TEST CASE: 3, list size: 3
Original list content:
	[ 5 18 19 ]
Zipped list content:
	[ 5 19 18 ]
TEST CASE: 4, list size: 8
Original list content:
	[ 3 4 22 1 20 3 15 1 ]
Zipped list content:
	[ 3 1 4 15 22 3 1 20 ]
TEST CASE: 5, list size: 14
Original list content:
	[ 5 6 4 4 3 23 8 17 21 17 6 14 12 6 ]
Zipped list content:
	[ 5 6 6 12 4 14 4 6 3 17 23 21 8 17 ]
TEST CASE: 6, list size: 9
Original list content:
	[ 1 16 20 20 8 2 19 2 12 ]
Zipped list content:
	[ 1 12 16 2 20 19 20 2 8 ]
TEST CASE: 7, list size: 14
Original list content:
	[ 20 10 3 12 15 16 9 0 19 0 1 15 3 7 ]
Zipped list content:
	[ 20 7 10 3 3 15 12 1 15 0 16 19 9 0 ]
TEST CASE: 8, list size: 4
Original list content:
	[ 18 18 2 1 ]
Zipped list content:
	[ 18 1 18 2 ]
TEST CASE: 9, list size: 10
Original list content:
	[ 23 12 10 17 23 8 8 20 14 15 ]
Zipped list content:
	[ 23 15 12 14 10 20 17 8 23 8 ]
TEST CASE: 10, list size: 13
Original list content:
	[ 19 6 11 1 2 17 19 22 22 8 6 10 11 ]
Zipped list content:
	[ 19 11 6 10 11 6 1 8 2 22 17 22 19 ]
 */