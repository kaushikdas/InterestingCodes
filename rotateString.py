import sys

def gcd(i, j):
    while i != j:
        if i > j: i -= j
        else    : j -= i
    return i

'''
Rotates LEFT string s by n positions
'''
def rotate(s, n):
    lst = list(s)
    sz = len(lst)
    g = gcd(n, sz)
    print("[Rotate] looping %d time(s)..." % g)
    for i in range(g):
        t = lst[i] # Temporarily store ith element
        j = i
        while True:
            k = j + n
            if k >= sz: k -= sz
            if k == i: break
            lst[j] = lst[k]
            j = k
        # Replace with original ith element
        lst[j] = t
    return "".join(lst)

def main():
    r = rotate(sys.argv[1], int(sys.argv[2]))
    print('Original String: ' + sys.argv[1])
    print('Rotated String: ' + r)

if __name__ == '__main__':
    main()

'''
SAMPLE OUTPUT

$ python3 rotateString.py abcdefgh 3
[Rotate] looping 1 time(s)...
Original String: abcdefgh
Rotated String: defghabc

$ python3 rotateString.py abcdefghi 3
[Rotate] looping 3 time(s)...
Original String: abcdefghi
Rotated String: defghiabc
'''
