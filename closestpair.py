import sys

class Point2D:
    def __init__(self, x, y):
        self.x = x; self.y = y

    def __eq__(self, other):
        if self.x == other.x and self.y == other.y: return True
        return False

    def comparePoints(self, other, compareX = True):
        if compareX == True: return self.x - other.x 
        return self.y - other.y
    
    def sqDistance(self, other):
        return ((self.x - other.x) * (self.x - other.x)) + \
                ((self.y - other.y) * (self.y - other.y)) 

class ClosestPair:
    def __init__(self):
        self.p = [] # points
        self.N = 0 # No. of points
        self.closestPt1 = Point2D(0, 0)
        self.closestPt2 = Point2D(0, 0)
        self.closestDistance = float('inf')

    def readTcInput(self):
        self.N = int(input())
        for j in range(self.N):
            coords = [int(i) for i in input().split(' ')]
            self.p += [Point2D(coords[0], coords[1])]

    '''
    merges sorted parts a[lo ... mid - 1] and a[mid ... hi - 1] 
    to a[lo ... hi - 1]
    '''
    def merge(self, a, lo, mid, hi, compareX = True):
        l = [] # left array
        r = [] # right array
        # Copy a[lo ... mid - 1] to l
        for i in range(lo, mid): l += [a[i]]
        # Copy a[mid ... hi - 1] to r
        for j in range(mid, hi): r += [a[j]]
        n1 = mid - lo # No. of elements in left array
        n2 = hi - mid # No. of elements in right array
        i = 0; j = 0
        for k in range(lo, hi):
            if   i == n1: a[k] = r[j]; j += 1
            elif j == n2: a[k] = l[i]; i += 1
            elif l[i].comparePoints(r[j], compareX) < 0: 
                          a[k] = l[i]; i += 1
            else:         a[k] = r[j]; j += 1
        
    def mergeSort(self, a, lo, hi, compareX = True):
        if (hi - lo) > 1:
            mid = (lo + hi) // 2
            self.mergeSort(a, lo, mid, compareX)
            self.mergeSort(a, mid, hi, compareX)
            self.merge(a, lo, mid, hi, compareX)

    # Find closest 
    def closest(self, ptsX, ptsY, lo, hi):
        if hi - lo <= 1:
            return float('inf')
        
        mid = (lo + hi) // 2
        minDistanceLeft = self.closest(ptsX, ptsY, lo, mid)
        minDistanceRight = self.closest(ptsX, ptsY, mid, hi)
        delta = min(minDistanceLeft, minDistanceRight)

        # Sort ptsY[lo ... mid ... hi - 1] on y cordinate
        self.merge(ptsY, lo, mid, hi, False)

        strip = []; m = 0
        for i in range(lo, hi):
            if abs(ptsY[i].x - ptsX[mid].x) < delta: 
                strip += [ptsY[i]]; m += 1
        
        for i in range(m):
            for j in range(i + 1, m):
                distance = strip[i].sqDistance(strip[j])
                if distance < delta:
                    delta = distance
                    if delta < self.closestDistance:
                        self.closestDistance = delta
                        self.closestPt1 = strip[i]
                        self.closestPt2 = strip[j]
        
        return delta 

    def find(self):
        if self.N <= 0:
            sys.stderr.write('No points given!'); return
        ptsX = []
        for i in range(self.N): ptsX += [self.p[i]]
        
        # Sort points on their x cordinates
        self.mergeSort(ptsX, 0, self.N - 1)
        # Now ptsX is sorted on x cordinate

        # Copy points sorted on x coordinate, ptsX, to another
        # array ptsY. While copy also check for COINCIDENT points.
        ptsY = []
        for i in range(self.N - 1):
            ptsY += [ptsX[i]]
            if ptsX[i] == ptsX[i + 1]:
                # Coincident point found
                self.closestDistance = 0.0
                self.closestPt1 = ptsX[i]
                self.closestPt2 = ptsX[i + 1]
                return
        ptsY += [ptsX[self.N - 1]] # Copy the final point outside loop

        self.closest(ptsX, ptsY, 0, self.N)

    def display(self):
        sys.stdout.write(str(self.closestDistance) + ' <(' \
            + str(self.closestPt1.x) + ', ' + str(self.closestPt1.y) \
            + '), (' + str(self.closestPt2.x) + ', ' \
            + str(self.closestPt2.y) + ')>\n')

    def getDistance(self):
        return self.closestDistance
        # self.mergeSort(self.p, 0, self.N, False)
        # for i in range(self.N):
        #     sys.stdout.write('(' + str(self.p[i].x) + ', ' + str(self.p[i].y) + ') ')
        # sys.stdout.write('\n')

def main():
    sys.stdin = open('.\\Python\closestpair.txt')
    TC = int(input())
    for t in range(TC):
        cp = ClosestPair()
        cp.readTcInput()
        cp.find()
        # sys.stdout.write('#' + str(t + 1) + ' ' \
        #                + str(cp.getDistance()) + '\n')
        sys.stdout.write('#' + str(t + 1) + ' ')
        cp.display()

    # Restore stdin
    sys.stdin = sys.__stdin__

if __name__ == '__main__': main()

'''
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
'''
