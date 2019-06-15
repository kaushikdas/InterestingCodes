#include <iostream>

using namespace std;

const int MAX_POINTS = 100000;
const long long MAX_DISTANCE = 99999999999L;

struct Point2D
{
    int x, y;

    Point2D() : x(0), y(0) {};
    Point2D(int xval, int yval) : x(xval), y (yval) {};

    inline bool operator ==(Point2D other)
    {
        return ((x == other.x) && (y == other.y));
    };

    inline int comparePoints(Point2D other, bool compareX = true)
    {
        return compareX ? (x - other.x) : (y - other.y);
    }

    inline long long sqDistance(Point2D other)
    {
        long long dx = (x - other.x), dy = (y - other.y);
        return (dx * dx + dy * dy);
    };

    inline long long sqDistanceX(Point2D other)
    {
        long long dx = (x - other.x);
        return (dx * dx);
    };

    inline long long sqDistanceY(Point2D other)
    {
        long long dy = (y - other.y);
        return (dy * dy);
    };
};

int N, ptsX[MAX_POINTS], ptsY[MAX_POINTS], closestPt1, closestPt2;
long long closestDistance;
Point2D p[MAX_POINTS];
int l[MAX_POINTS], r[MAX_POINTS], strip[MAX_POINTS];

class ClosestPair
{
    /**
     * merges sorted parts a[lo ... mid - 1] and a[mid ... hi - 1] 
     * to a[lo ... hi - 1]
     */
    void merge(int a[], int lo, int mid, int hi, bool compareX = true)
    {
        int i, j, k, 
            n1 = mid - lo, // No. of elements in left array
            n2 = hi - mid; // No. of elements in right array

        // Copy a[lo ... mid - 1] to l
        for (i = 0; i < n1; ++i) l[i] = a[lo + i];
        // Copy a[mid ... hi - 1] to r
        for (j = 0; j < n2; ++j) r[j] = a[mid + j];

        i = j = 0;
        for (k = lo; k < hi; ++k) {
            if (i == n1)
                a[k] = r[j++];
            else if (j == n2)
                a[k] = l[i++];
            else if (p[l[i]].comparePoints(p[r[j]], compareX) < 0)
                a[k] = l[i++];
            else
                a[k] = r[j++];
        }
    }

    void mergeSort(int a[], int lo, int hi, bool compareX = true)
    {
        if ((hi - lo) > 1) {
            int mid = (hi + lo) / 2;
            mergeSort(a, lo, mid, compareX);
            mergeSort(a, mid, hi, compareX);
            merge(a, lo, mid, hi, compareX);
        }
    };

    inline long long getMin(long long d1, long long d2)
    {
        return (d1 < d2) ? d1 : d2;
    };

    // Find closest pair and (square) distance
    long long closest(int lo, int hi)
    {
        if ((hi - lo) <= 1)
            return MAX_DISTANCE;

        int mid = (hi + lo) / 2;
        long long minDistanceLeft = closest(lo, mid);
        long long minDistanceRight = closest(mid, hi);
        long long delta = getMin(minDistanceLeft, minDistanceRight);

        // Sort ptsY[lo ... mid ... hi - 1] on y cordinate
        merge(ptsY, lo, mid, hi, false);

        int m = 0;
        long long dx2 = 0;
        for (int i = lo; i < hi; ++i) {
            dx2 = p[ptsX[mid]].sqDistanceX(p[ptsY[i]]);
            if (dx2 < delta)
                strip[m++] = ptsY[i];
        }

        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j < m; ++j) {
                auto dy2 = p[strip[i]].sqDistanceY(p[strip[j]]);
                // The below check will ensure that the for loop
                // of j runs for a maximum of 7 times
                if (dy2 >= delta) break;
                auto d2 = p[strip[i]].sqDistance(p[strip[j]]);
                if (d2 < delta) {
                    delta = d2;
                    if (delta < closestDistance) {
                        closestDistance = delta;
                        closestPt1 = strip[i];
                        closestPt2 = strip[j];
                    }
                }
            }
        
        return delta;
    };

public:
    void readTcInput()
    {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> p[i].x >> p[i].y;
        }
        closestDistance = MAX_DISTANCE;
        closestPt1 = closestPt2 = 0;
    };

    void find()
    {
        if (N <= 0) {
            cerr << "No points specified!" << endl;
            return;
        }

        for (int i = 0; i < N; ++i) ptsX[i] = i;

        // Sort points on their x cordinates
        mergeSort(ptsX, 0, N);
        // Now ptsX is sorted on x cordinate

        // Copy points sorted on x coordinate, ptsX, to another
        // array ptsY. While copy also check for COINCIDENT points.
        for (int i = 0; i < (N - 1); ++i) {
            ptsY[i] = ptsX[i];
            if (p[ptsX[i]] == p[ptsX[i + 1]]) {
                // Coincident point found
                closestDistance = 0;
                closestPt1 = i;
                closestPt2 = i + 1;
                return;
            }
        }
        // Copy the final point outside loop
        ptsY[N - 1] = ptsX[N - 1];

        closest(0, N);
    };

    long long getDistance()
    {
        return closestDistance; 
    };

    void display()
    {
        cout << closestDistance << " <(" << p[closestPt1].x 
             << ", " << p[closestPt1].y << "), (" << p[closestPt2].x 
             << ", " << p[closestPt2].y << ")>\n";
    }
};

int main()
{
    // freopen("closestpair.txt", "r", stdin);

    int t = 0, TC = 0;
    cin >> TC;
    for (t = 0; t < TC; ++t) {
        ClosestPair cp;
        cp.readTcInput();
        cp.find();
        cout << "#" << t + 1 << " ";
        //cp.display();
        cout << cp.getDistance() << "\n";
    }
    return 0;
}
///:~

/* 
SAMPLE INPUT
2
6
2 3
12 30
40 50
5 1
12 10
3 4
4
0 0
10 10
0 10
10 0

SAMPLE OUTPUT
#1 2 <(2, 3), (3, 4)>
#2 100 <(0, 0), (0, 10)>
*/
