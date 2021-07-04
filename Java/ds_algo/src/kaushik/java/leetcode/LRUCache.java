package kaushik.java.leetcode;

import java.util.HashMap;

class Dll<K, V> {
    static class Node<T, U> {
        T k;
        U v;

        Node<T, U> next;
        Node<T, U> prev;

        Node(T k, U v) {
            this.k = k;
            this.v = v;
        }
    }

    private Node<K, V> sentinelHead;
    private Node<K, V> sentinelTail;

    public Dll(K k, V v) {
        sentinelHead = new Node<>(k, v);
        sentinelTail = new Node<>(k, v);

        sentinelHead.next = sentinelTail;
        sentinelTail.prev = sentinelHead;
    }

    public void remove(Node<K, V> nd) {
        nd.prev.next = nd.next;
        nd.next.prev = nd.prev;
    }

    public void addFirst(Node<K, V> nd) {
        nd.next = sentinelHead.next;
        sentinelHead.next.prev = nd;
        nd.prev = sentinelHead;
        sentinelHead.next = nd;
    }

    public Node<K, V> removeLast() {
        Node<K, V> nd = sentinelTail.prev;

        sentinelTail.prev = nd.prev;
        nd.prev.next = sentinelTail;

        nd.prev = null;
        nd.next = null;

        return nd;
    }

    public void moveToFirst(Node<K, V> nd) {
        if (nd != sentinelHead.next) {
            // This node is NOT already the first node
            remove(nd);
            addFirst(nd);
        }
    }
}


class LRUCache {
    private int capacity;

    private HashMap<Integer, Dll.Node<Integer, Integer>> hm;
    private Dll<Integer, Integer> keyList;

    public LRUCache(int capacity) {
        this.capacity = capacity;

        hm = new HashMap<>();
        keyList = new Dll<>(0, 0);
    }

    public int get(int key) {
        Dll.Node<Integer, Integer> nd = hm.get(key);

        if (nd != null) { // key exists
            // Make this key as recent key
            keyList.moveToFirst(nd);
            return nd.v;
        }
        return -1;
    }

    public void put(int key, int value) {
        Dll.Node<Integer, Integer> nd = hm.get(key);

        if (nd != null) { // key exists
            // Make this key as recent key
            keyList.moveToFirst(nd);

            // key exists - update value in map
            nd.v = value;
            // hm.put(key, nd); // --> This put is redundant
        }
        else {
            // check if the hm is full
            if (hm.size() < capacity) { // hm is not full
                nd = new Dll.Node<>(key, value);
                hm.put(key, nd);
                keyList.addFirst(nd);
            }
            else {
                // evict the LRU key
                nd = keyList.removeLast();

                hm.remove(nd.k);

                nd.k = key;
                nd.v = value;
                keyList.addFirst(nd);
                hm.put(key, nd);
            }
        }
    }

    public static void main(String[] args) {
        LRUCache obj = new LRUCache(3);

        //["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
        //[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]

        obj.put(1, 1);
        obj.put(2, 2);
        obj.put(3, 3);
        obj.put(4, 4);
        System.out.println(obj.get(4));
        System.out.println(obj.get(3));
        System.out.println(obj.get(2));
        System.out.println(obj.get(1));
        obj.put(5, 5);
        System.out.println(obj.get(1));
        System.out.println(obj.get(2));
        System.out.println(obj.get(3));
        System.out.println(obj.get(4));
        System.out.println(obj.get(5));

        /*
        4
        3
        2
        -1
        -1
        2
        3
        -1
        5
        */
    }
}