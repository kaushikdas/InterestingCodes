# imports
import mysql.connector as sqltor

# print a banner
print('**************************')
print('* Bank Management System *'.upper())
print('**************************')

print('Log in to the system\n')
userName = ''
password = ''
# Should fail after 3 login attempts
for i in range(3):
    userName = input('Enter the user name: ')
    password = input('Enter the password: ')
    # validate entered username and password
    if userName != 'maharnab' or password != 'maharnab':
        print('> ERROR: Wrong user name or password!')
        print('> Remaining', 3-i-1, 'attempts!')
    else:
        break
else:
    print('> [ERROR] Failed to login! EXIT!')
    exit()
    
# connect to mysql
print('> Initiailizing bank management system...')
print('> Logging into the database...')
dbCon = sqltor.connect(host='localhost', user=userName, passwd=password)

if dbCon.is_connected() == True:
    print('> Successfully logged into the database...')
else:
    print('> [ERROR] Failed logged into the database. EXIT')

dbCursor = dbCon.cursor()
    
# create database if not already exists
databaseName = 'bank_db'
dbCursor.execute('CREATE DATABASE IF NOT EXISTS ' + databaseName)
dbCursor.execute('USE ' + databaseName)

# check accounts table
print('> Checking accounts table...')
accountTableName = 'bank_accs'
createTableQuery = f'''CREATE TABLE IF NOT EXISTS {accountTableName} (
        accno       CHAR(10)    NOT NULL PRIMARY KEY,
        acctype     CHAR(4)     NOT NULL,
        accname     VARCHAR(20),
        createdate  DATE,
        updatedate  DATE,
        balance     DECIMAL
    )
'''
dbCursor.execute(createTableQuery)
dbCursor.execute('SELECT * FROM ' + accountTableName)
data = dbCursor.fetchall()
print(f'> Found details of {dbCursor.rowcount} accounts...')

customerTableName = 'bank_custs'
print('> Checking customer table...')
customerTableName = 'bank_custs'
createTableQuery = f'''CREATE TABLE IF NOT EXISTS {customerTableName} (
        custid      INT UNSIGNED NOT NULL AUTO_INCREMENT,
        custname    VARCHAR(30),
        mobile      CHAR(10),
        address     VARCHAR(50),
        accno       CHAR(10),
        PRIMARY KEY (custid, accno),
        FOREIGN KEY (accno) REFERENCES bank_accs(accno)
    )
'''
dbCursor.execute(createTableQuery)
dbCursor.execute('SELECT * FROM ' + customerTableName)
data = dbCursor.fetchall()
print(f'> Found details of {dbCursor.rowcount} customers...')