poem=open('Sarojini Poem.txt', 'r')
lines = poem.readlines()
poem.close()

print(len(lines), 'lines in the file')
l=0
u=[]
sum1=0
for line in lines:
    if line == '\n':
        l+=1
    else:
        sum1+=len(line)
    u.append(len(line))
print(l, 'empty lines')
print(((sum(u))/len(lines)), 'average characters per line')
print(sum1/(len(lines)-l), 'average characters per non-empty line')

