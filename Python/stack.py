def PUSH(stk):
    a=input("Enter city to be added:")
    stk.append(a)
def POP(stk):
    if len(stk)>=0:
        c=stk.pop()
        print('The popped city is:',c)
    else:
        print('STACK UNDERFLOW')
def DISPLAY(stk):
    if len(stk)==0:
        print("Empty stack")
    else:
        print(stk[-1],'<--TOP')
        for i in range(len(stk)-2,-1,-1):
            print(stk[i])
print("STACK IMPLEMENTATION PROGRAM")
stk=[]
ans='y'
while ans.lower()=='y':
    print("1 PUSH\n2 POP\n3 DISPLAY\n4 Exit")
    ch=int(input("Enter your choice:"))
    if ch==1:
        PUSH(stk)
    elif ch==2:
        POP(stk)
    elif ch==3:
        DISPLAY(stk)
    elif ch==4:
        break
