# Create the csv file which should contains the employee details and 
# to search the particular employee based on empno and display 
# the details.


import csv

def addrec():
    with open("./Python/emp.csv", 'a', newline='') as a:
        b = csv.writer(a)
        l = []
        ans = 'y'
        while ans == 'y':
            eno = int(input("Enter emp no:"))
            ename = input("Enter emp name:")
            s = int(input("Enter emp salary:"))
            l.append([eno, ename, s])
            print(l)
            ans =input("Do you want to add another record(y/n):")
        b.writerows(l)
    print("Records stored successfully!.")


def searchrec():
    l = []
    with open("./Python/emp.csv",'r') as a:
        b = csv.reader(a)
        eno = input("Enter the emp no which you want to search:")
        for i in b:
            l.append(i)
        for i in l:
            if eno == i[0]:
                print("Emp no:", i[0],"\nEmp Name:", i[1],
                      "\nEmp salary:",i[2])
                break
        else:
            print("Entered emp no not found in the file")


print("Emp record search program")

addrec()
searchrec()
