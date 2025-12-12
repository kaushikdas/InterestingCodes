# Create the binary file whcih which should contains the student
# details and to update file which based on rollno.

import pickle


def addrec():
    a = open("./Python/student.bin",'wb')
    print("Add student details")
    l = []
    ans = 'y'
    while ans == 'y':
        r = int(input("Enter the roll no:"))
        n = input("Enter name :")
        m = float(input("Enter mark:"))
        l.append([r, n, m])
        ans = input("Do you want to add another record(y/n):")
    
    pickle.dump(l, a)
    a.close()
    print("Records stored successfully!.")
    
def updaterec():
    a = open("./Python/student.bin",'rb+')
    r = int(input("Enter the roll no which you want to update:"))
    b = pickle.load(a)
    print(b)
    l = []
    for i in b:
        l.append(i)
    for i in l:
        if r == i[0]:
           nm=float(input("Enter new marks:"))
           i[2] = nm
        break
    else:
        print("Entered Roll no not found in the file")
    
    a.seek(0)
    pickle.dump(l,a)
    print("Record updated successfully")
    print()
    a.close()
    
print("Student record update program")
addrec()
updaterec()
