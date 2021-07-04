package kaushik.java.leetcode;

import java.util.HashMap;

class LFUNode<D> {
    D d;

    LFUNode<D> prev;
    LFUNode<D> next;
}

class LFUData {
    int k;
    int v;
    int f;
    LFUNode<LFUDll<LFUData>> containerNode;

    LFUData() {
        k = 0; v = 0; f = 0;
        containerNode = null;
    }

    LFUData(int k, int v, int f) {
        this.k = k;
        this.v = v;
        this.f = f;
        this.containerNode = null;
    }
}

class LFUDll<E> {
    private LFUNode<E> head;
    private LFUNode<E> tail;

    public LFUDll() {
        head = new LFUNode<>();
        tail = new LFUNode<>();

        head.next = tail;
        tail.prev = head;
    }

    public boolean isEmpty() {
        if (head.next == tail)  return true;

        return false;
    }

    public boolean isLast(LFUNode<E> nd) {
        if (nd.next == tail)    return true;

        return false;
    }

    public void remove(LFUNode<E> nd) {
        nd.next.prev = nd.prev;
        nd.prev.next = nd.next;
    }

    public void addLast(LFUNode<E> nd) {
        nd.next = tail;
        nd.prev = tail.prev;
        tail.prev.next = nd;
        tail.prev = nd;
    }

    public LFUNode<E> addLast(E e) {
        LFUNode<E> nd = new LFUNode<>();
        nd.d = e;

        addLast(nd);

        return nd;
    }

    public void add(LFUNode<E> nd) {   // add to Head
        nd.prev = head;
        nd.next = head.next;
        head.next = nd;
        nd.next.prev = nd;
    }

    public LFUNode<E> add(E e) {   // add to Head
        LFUNode<E> nd = new LFUNode<>();
        nd.d = e;

        add(nd);

        return nd;
    }

    public void addAfter(LFUNode<E> nd1, LFUNode<E> nd2) { // add nd2 after nd1
        nd2.next = nd1.next;
        nd2.prev = nd1;
        nd1.next.prev = nd2;
        nd1.next = nd2;
    }

    public LFUNode<E> addAfter(LFUNode<E> nd1, E e) {
        LFUNode<E> nd = new LFUNode<>();
        nd.d = e;

        addAfter(nd1, nd);

        return nd;
    }

    public LFUNode<E> peek() {
        return head.next;
    }

    public LFUNode<E> removeLast() {
        LFUNode<E> nd = tail.prev;

        tail.prev = nd.prev;
        tail.prev.next = tail;

        nd.prev = null;
        nd.next = null;

        return nd;
    }
}

class LFUCache {
    private HashMap<Integer, LFUNode<LFUData>> hm;
    private LFUDll<LFUDll<LFUData>> container;

    private int capacity;

    public LFUCache(int capacity) {
        this.capacity = capacity;

        hm = new HashMap<>();
        container = new LFUDll<>();
    }

    private void addNewFreqBucket(LFUNode<LFUDll<LFUData>> containerNode,
                                  LFUNode<LFUData> nd) {

        // Create new Dll container
        LFUDll<LFUData> newDll = new LFUDll<>();
        // add nd to newDll
        newDll.add(nd);
        // add newDll to container
        LFUNode<LFUDll<LFUData>> newContainerNode
                = container.addAfter(containerNode, newDll);
        // update container node for d
        nd.d.containerNode = newContainerNode;
    }

    private void incrementKeyFreq(LFUNode<LFUData> nd) {
        LFUData d = nd.d;
        d.f += 1;

        // move this node to next frequency bucket
        LFUNode<LFUDll<LFUData>> containerNode = d.containerNode;
        // remove the node from container node dll
        LFUDll<LFUData> containerNodeDll = containerNode.d;
        containerNodeDll.remove(nd);

        if (container.isLast(containerNode)) {
            addNewFreqBucket(containerNode, nd);
        }
        else {
            LFUNode<LFUDll<LFUData>> nextContainerNode = containerNode.next;
            LFUDll<LFUData> nextContainerNodeDll = nextContainerNode.d;
            LFUNode<LFUData> head = nextContainerNodeDll.peek();
            if (head.d.f == d.f) {
                d.containerNode = nextContainerNode;
                // add nd to nextDll
                nextContainerNodeDll.add(nd);
            }
            else if (head.d.f > d.f) {
                addNewFreqBucket(containerNode, nd);
            }
            else {
                // We MUST never come here
                throw new AssertionError("[incrementKeyFreq] Ouch!");
            }
        }
        if (containerNodeDll.isEmpty()) {
            // remove this container node
            container.remove(containerNode);
        }
    }

    public int get(int key) {
        LFUNode<LFUData> nd = hm.get(key);

        if (nd != null) {
            // key found

            // increment the access frequency of this node
            incrementKeyFreq(nd);
            return nd.d.v;
        }

        // key not found
        return -1;
    }

    private LFUNode<LFUData> addNewNode(int key, int value) {
        LFUNode<LFUDll<LFUData>> headContainerNode = container.peek();
        LFUData d = new LFUData(key, value, 1);

        LFUNode<LFUData> newNode = null;
        if (container.isEmpty()
                || (headContainerNode.d.peek().d.f > 1)) {
            // create a new container list
            LFUDll<LFUData> newDll = new LFUDll<>();
            newNode = newDll.add(d);
            LFUNode<LFUDll<LFUData>> newContainerNode = container.add(newDll);
            d.containerNode = newContainerNode;
        }
        else if (headContainerNode.d.peek().d.f == 1) {
            // add to the list in headContainerNode
            d.containerNode = headContainerNode;
            newNode = headContainerNode.d.add(d);
        }
        else {
            // We MUST never come here
            throw new AssertionError("[put] addNewNode!");
        }

        return newNode;
    }

    public void put(int key, int value) {
        LFUNode<LFUData> nd = hm.get(key);

        if (nd != null) {
            // existing key

            // increment the access frequency of this node
            incrementKeyFreq(nd);
            // Update value
            nd.d.v = value;
        }
        else {
            // new key
            if (hm.size() >= capacity) {
                // evict the LFU node
                LFUNode<LFUDll<LFUData>> headContainerNode = container.peek();
                if (headContainerNode == null) {
                    throw new AssertionError("[put] Ouch!");
                }
                LFUNode<LFUData> lfuNd = headContainerNode.d.removeLast();
                if (headContainerNode.d.isEmpty()) {
                    container.remove(headContainerNode);
                }
                hm.remove(lfuNd.d.k);
            }
            LFUNode<LFUData> newNode = addNewNode(key, value);
            hm.put(key, newNode);
        }
    }

    public static void main(String[] args) {

        // ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
        // [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
        LFUCache lfu = new LFUCache(2);
        lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
        lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
        System.out.println(lfu.get(1));;      // return 1
        // cache=[1,2], cnt(2)=1, cnt(1)=2
        lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
        // cache=[3,1], cnt(3)=1, cnt(1)=2
        System.out.println(lfu.get(2));;      // return -1 (not found)
        System.out.println(lfu.get(3));;      // return 3
        // cache=[3,1], cnt(3)=2, cnt(1)=2
        lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
        // cache=[4,3], cnt(4)=1, cnt(3)=2
        System.out.println(lfu.get(1));;      // return -1 (not found)
        System.out.println(lfu.get(3));;      // return 3
        // cache=[3,4], cnt(4)=1, cnt(3)=3
        System.out.println(lfu.get(4));;      // return 4
        // cache=[3,4], cnt(4)=2, cnt(3)=3
        /*
        // ["LFUCache","put","get","put","get","get"]
        // [[1],[2,1],[2],[3,2],[2],[3]]
        LFUCache lfu = new LFUCache(1);
        lfu.put(2, 1);
        System.out.println(lfu.get(2));
        lfu.put(3, 2);
        System.out.println(lfu.get(2));
        System.out.println(lfu.get(3));

         */
    }
}
