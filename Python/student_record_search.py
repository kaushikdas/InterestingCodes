# Create the binary file which should contains
# particular student based On rollno and display the the student details.

import pickle

def addrec():
    a = open("./Python/student.bin",'wb')
    print("Add student details")
    l = []
    ans = 'y'
    while ans == 'y':
        r = int(input("Enter the roll no:"))
        n = input("Enter name:")
        m = float(input("Enter mark:"))
        l.append([r,n,m])
        print(l)
        ans =input("Do you want to add another record(y/n):")
    pickle.dump(l,a)
    print("Records stored successfully!.")
    a.close()


def searchrec():
    a = open("./Python/student.bin",'rb')
    r = int(input("Enter the roll no which you want to search:"))
    b = pickle.load(a)
    for i in b:
        if r == i[0]:
            print("Roll no:",i[0],"InName:",i[1],"\nMark:",i[2])
            break
    else:
        print("Entered Roll no not found in the file")
    a.close()


print("Student record search program")

addrec()
searchrec()
