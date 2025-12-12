import csv

f1 = open('simple.csv', 'w')
w = csv.writer(f1)
L = [
    ['Name', 'Gender'],
    ['Kaushik', 'M'],
    ['Pratima', 'F'],
    ['Maharnab', 'M']
]
w.writerows(L)
f1.close()

f2 = open('simple.csv', 'r')
lines = f2.read()
print(lines)
for line in lines:
    print(type(line))
    for c in line:
        print(c)

f2.close()

