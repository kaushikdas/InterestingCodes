f = open('passwords.txt', 'r+')
fileContent = f.read()

while True:
    userid = input('Enter userid: ')
    su = 'user_id: ' + userid + '\n'
    if fileContent.find(su) == -1:
        # userid does not exist in the file
        while True:
            password = input('Enter password: ')
            if len(password) >= 8:
                passwordok = False
                for c in password:
                    if c in '0123456789':
                        for x in password:
                            if x in '@$%':
                                passwordok = True
                if passwordok == False:
                    print('No special character in password')
                    continue
                else:
                    break
            else:
                print('Too short password ')
                continue
        
        line = 'user_id: ' + userid + '\n' \
               + 'password: ' + password + '\n'
        f.write(line)
        break
    else:
        print('User id already exists')
        continue
    
f.close()