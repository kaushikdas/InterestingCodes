import sys

# NOT USED


def gcdEuclidianAdditive(i, j):
    while i != j:
        if i > j:
            i -= j
        else:
            j -= i
    return i

# NOT USED


def gcdEucid(i, j):
    if j == 0:
        return i
    return gcdEucid(j, i % j)


'''
Binary GCD
gcd(i, j) =
  * i if j = 0
  * j if i = 0
  * 2 * gcd(i/2, j/2) if i & j are even, because 2 is common factor
  * gcd(i/2, j) if i is even & j is odd, because 2 isn't common factor
  * gcd(i, j/2) if i is odd and j is even, because 2 isn't common factor
  * gcd((i-j)/2, j) if i and j are odd and i >= j
  * gcd(i, (j-i)/2) if i and j are odd and i < j 
'''


def gcdBinary(i, j):
    if j == 0:
        return i
    if i == 0:
        return j

    # i and j even
    if ((i & 1) == 0 and (j & 1) == 0):
        return gcdBinary(i >> 1, j >> 1) << 1
    # i is even, j is odd
    elif ((i & 1) == 0):
        return gcdBinary(i >> 1, j)
    # i is odd, j is even
    elif ((j & 1) == 0):
        return gcdBinary(i, j >> 1)
    # i and j odd, i >= j
    elif (i >= j):
        return gcdBinary((i-j) >> 1, j)
    # i and j odd, i < j
    else:
        return gcdBinary(i, (j-i) >> 1)


def rotate(s, n):
    '''Rotates LEFT string s by n positions

    Args:
        s (string): Input string to rotate
        n (int): Number of characters to be rotated

    Returns:
        [NA]: NA
    '''
    lst = list(s)

    # * Use Juggling algorithm to rotate a string

    sz = len(lst)
    g = gcdBinary(n, sz)
    print('[Rotate] looping {} time(s)...'.format(g))
    for i in range(g):
        t = lst[i]  # Temporarily store ith element
        j = i
        while True:
            k = j + n
            if k >= sz:
                k -= sz
            if k == i:
                break
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
