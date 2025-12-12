# Read text file and display the number of
# vowels/consonants/uppercase/lowercase characters in the file.
a=open('sample.txt','r')
b=a.read()
v = c=uc=lc=0
for i in b:
    if i.isalpha():
        if i in 'aeiouAEIOU':
            v += 1
        else:
            c += 1
    if i.isupper():
        uc += 1
    elif i.islower():
        lc += 1
print("The number of vowels in the file is :", v)
print("The number of consonants in the file is :", c)
print("The number of upper case letters in the file is :", uc)
print("The number of lower case letters in the file is :", lc)
a.close()
