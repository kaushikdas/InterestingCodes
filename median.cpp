#include <cstdio>

const int SZ = 100;
const int MAX_HEAP_SZ = (SZ >> 1) + (SZ & 0x1);
const int MIN_HEAP_SZ = (SZ >> 1);

static inline int parent(int i)
{
    if (i > 1) return i >> 1;
    return i;
}

static inline int left(int i)
{
    return i << 1;
}

static inline int right(int i)
{
    return ((i << 1) + 1);
}

class MaxHeap {
    int a[MAX_HEAP_SZ + 1];
    int sz;
    inline void exchange(int i, int j)
    {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    void maxHeapify(int i)
    {
        if (i == sz) return;
        int l = left(i), r = right(i), max = i;
        if ((l <= sz) && (a[l] > a[max])) max = l;
        if ((r <= sz) && (a[r] > a[max])) max = r;
        if (i != max) {
            exchange(i, max);
            maxHeapify(max);
        }
    }
public:
    MaxHeap() : sz(0) {};
    void insert(int v) 
    {
        if (sz >= MAX_HEAP_SZ) {
            printf("Insert fail - max heap full\n");
            return;
        }
        sz++;
        a[sz] = v;
        int i = sz;
        while (i > 1) {
            int p = parent(i);
            if (a[i] <= a[p]) {
                break;
            }
            exchange(i, p);
            i = p;
        }
    }

    int remove() // removes max element 
    {
        if (sz == 0) {
            printf("remove: Empty maxHeap\n");
            return -1;
        }
        int top = a[1];
        a[1] = a[sz];
        sz--;
        maxHeapify(1);
        return top;
    }

    inline int peek() {
        if (sz > 0) return a[1];
        else {
            printf("peek: Empty maxHeap\n");
            return -1;
        }
    }

    inline int size() {
        return sz;
    }
};

class MinHeap {
    int a[MIN_HEAP_SZ + 1];
    int sz;
    inline void exchange(int i, int j)
    {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    void minHeapify(int i)
    {
        if (i == sz) return;
        int l = left(i), r = right(i), min = i;
        if ((l <= sz) && (a[l] < a[min])) min = l;
        if ((r <= sz) && (a[r] < a[min])) min = r;
        if (i != min) {
            exchange(i, min);
            minHeapify(min);
        }
    }
public:
    MinHeap() : sz(0) {};
    void insert(int v) 
    {
        if (sz >= MIN_HEAP_SZ) {
            printf("Insert fail - min heap full\n");
            return;
        }
        sz++;
        a[sz] = v;
        int i = sz;
        while (i > 1) {
            int p = parent(i);
            if (a[i] >= a[p]) {
                break;
            }
            exchange(i, p);
            i = p;
        }
    }

    int remove() // removes min element 
    {
        if (sz == 0) {
            printf("remove: Empty minHeap\n");
            return -1;
        }
        int top = a[1];
        a[1] = a[sz];
        sz--;
        minHeapify(1);
        return top;
    }

    inline int peek() {
        if (sz > 0) return a[1];
        else {
            printf("peek: Empty minHeap\n");
            return -1;
        }
    }

    inline int size() {
        return sz;
    }
};

class MedianFinder {
    MaxHeap maxHeap;
    MinHeap minHeap;
public:
    int add(int v) 
    {
        // Invariant: size of the maxHeap and minHeap have same number
        // of elements or the maxHeap has at most 1 element extra.
        // If they have same number of elements top of the heaps
        // are two medians else maxHeap top is the median.
        int maxHeapSz = maxHeap.size(), minHeapSz = minHeap.size();
        if (maxHeapSz == minHeapSz) {
            // both heaps have same number of elements
            int minTop = 0;
            if ((minHeapSz > 0) && ((minTop = minHeap.peek()) < v)) {
                // minHeap is not empty and the new element is larger
                // than the minHeap top element
                // .. (1) remove minHeap top
                // .. (2) add that to maxHeap (now it has 1 elm extra)
                // .. (3) add the new element to minHeap
                minHeap.remove();
                maxHeap.insert(minTop);
                minHeap.insert(v);
            }
            else {
                // either minHeap is empty or new element is smaller
                // than its top. Since both heaps have same number of
                // elements add the new element to maxHeap
                maxHeap.insert(v);
            }
        }
        else { // maxHeap has one extra element
            int maxTop = maxHeap.peek();
            if (v < maxTop) {
                // new element is smaller than maxHeap top
                // .. (1) remove maxHeap top
                // .. (2) add that to minHeap (now both has same size)
                // .. (3) add new element to maxHeap
                maxHeap.remove();
                minHeap.insert(maxTop);
                maxHeap.insert(v);
            }
            else {
                // new element is larger than maxHeap top
                // .. add new element to minHeap so that
                // .. they will have same size maintaining the
                // .. required invariant
                minHeap.insert(v);
            }
        }
    }

    int getMedian(int m[]) {
        if (maxHeap.size() == 0) {
            return 0;
        }
        if (maxHeap.size() == minHeap.size()) {
            m[0] = maxHeap.peek();
            m[1] = minHeap.peek();
            return 2;
        }
        m[0] = maxHeap.peek();
        return 1;
    }
};

int main()
{
    MedianFinder mf;
    for (int i = 1; i <= 10; ++i) {
        mf.add(i);
        int a[2];
        int r = mf.getMedian(a);
        printf("<%d> ", i);
        switch(r) {
        case 2:
            printf("Median: [%d, %d]\n", a[0], a[1]);
            break;
        case 1:
            printf("Median: [%d]\n", a[0]);
            break;
        case 0:
        default:
            printf("Median: [%d]\n", a[0]);
            break;
        }
    }
    return 0;
}

/*
SAMPLE OUTPUT

PS C:\TestPrograms> cd "c:\TestPrograms\CnC++\" ; if ($?) { g++ median.cpp -o median } ; if ($?) { .\median }
<1> Median: [1]
<2> Median: [1, 2]
<3> Median: [2]
<4> Median: [2, 3]
<5> Median: [3]
<6> Median: [3, 4]
<7> Median: [4]
<8> Median: [4, 5]
<9> Median: [5]
<10> Median: [5, 6]
*/
