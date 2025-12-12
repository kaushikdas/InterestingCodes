filename = input('File name? ')
f = open(filename)
# content = f.read()

# print(content.upper())

print(f.read().upper())
f.close()

f = open(filename)
print(f.readlines())
