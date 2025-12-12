f = open('./Python/poem.txt', 'r')
b = f.readline()
while b:
    c = b.split()
    for i in range(len(c)-1):
        print(c[i], '#', end='', sep='')
    print(c[-1])
    # print()
    b = f.readline()
f.close()
