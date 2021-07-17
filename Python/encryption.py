# https://www.hackerrank.com/challenges/encryption/problem

# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#


def encryption(s):
    # Write your code here
    src = ''
    L = 0
    for c in s:
        if c != ' ':
            src += c
            L += 1

    n = 2
    while n*n < L:
        n += 1

    result = ''
    for j in range(n):
        for k in range(j, L, n):
            result += src[k]
        if j != n-1:
            result += ' '

    return str(result)


if __name__ == '__main__':
    s = encryption('haveaniceday')
    print(s)
    s = encryption('feedthedog')
    print(s)
