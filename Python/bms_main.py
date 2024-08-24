import bms_database as bankDb


def displayMenu():
    print('+--------------------------------------------+')
    print('| BANK OPERATION MENU                        |')
    print('|                                            |')
    print('|   Available operations                     |')
    print('|                                            |')
    print('|   1. Create customer                       |')
    print('|   2. Open bank account                     |')
    print('|   3. Get account details                   |')
    print('|   4. Delete bank account                   |')
    print('|   5. Transact                              |')
    print('|   6. Quit                                  |')
    print('+--------------------------------------------+\n')


def getCustInfo():
    print('ENTER CUSTOMER DETAILS')
    name = input('  Customer name? ')
    mobile = input('  Mobile number? ')
    address = input('  Address? ')
    return (name, mobile, address)


def newCustomer(dbCon, dbCursor):
    (name, mobile, address) = getCustInfo()
    (insertedRowCount, newCustId) = bankDb.addCustToDb(
        dbCon, dbCursor, name, mobile, address)
    print(insertedRowCount, 'new customer added. custid:', newCustId)


def deleteCustomer(dbCon, dbCursor):
    custid = input('Enter custid to delete: ')
    count = bankDb.deleteCustomerFromDb(dbCon, dbCursor, custid)
    if count == 1:
        print('Deleted customer, custid:', custid)
    else:
        print('Delete customer failed! custid:', custid)


def openBankAcc(dbCon, dbCursor):
    print('CREATING A NEW BANK ACCOUNT')
    accType = "SBAC"
    prefix = 'S'
    print('  Step 1 - Account Type Selection')
    print('  1. Savings\n  2. Current\n  3. Fixed deposit\n')
    typeInp = int(input('  Choose account type (1/2/3): '))
    if typeInp == 1:
        accType = "SBAC"
        accName = 'Savings Account'
        prefix = 'S'
    elif typeInp == 2:
        accType = "CUAC"
        accName = 'Current Account'
        prefix = 'C'
    elif typeInp == 3:
        accType = "FDAC"
        accName = 'Fixed Account'
        prefix = 'F'
    else:
        print('> Failed! Wrong account type ({typeInp})!')
        return False

    print('\n  Step 2 - Primary Customer Selection')
    primCustId = input('  Enter custid of primary Customer: ')
    data = bankDb.fetchCustomerDetailsFromDb(dbCursor, primCustId)
    if data == None:
        print('Failed to open acc. No such primary customer!')
        return False
    print('\n  Step 3 - Joint Customer Selection')
    isJtAcc = input('  Any joint customer (y/n)?')
    if isJtAcc == 'y':
        jtCustId = input('  Enter custid of joint Customer:')
        data = bankDb.fetchCustomerDetailsFromDb(dbCursor, jtCustId)
        if data == None:
            print('Failed to open acc. No such joint customer.')
            return False
    else:
        jtCustId = primCustId
    print('\n  Step 4 - Enter creation date')
    createDate = input('  Create date (YYYY-MM-DD)? ')

    balance = float(input('  Enter initial account balance: '))

    accCount = bankDb.getAccCountFromDb(dbCursor)
    accNo = prefix + str(accCount + 1)

    insertedRowCount = bankDb.addAccToDb(dbCon, dbCursor,
                                         accNo, accType, accName, primCustId, jtCustId,
                                         createDate, createDate, balance)
    if insertedRowCount == 1:
        print('Successfully opened account. accNo:', accNo)
        return True
    else:
        print('Failed to open account.')
        return False


def getAccDetails(dbCursor):
    accNo = input('Enter accNo: ')
    data = bankDb.fetchAccDetailsFromDb(dbCursor, accNo)
    if data != None:
        print('ACCOUNT DETAILS')
        print('(accno, acctype, accname, prmcustid, jtcustid, ' +
              'createdate, updatedate, balance)')
        print(data)
    else:
        print('Account NOT found. accNo =', accNo)


def deleteAcc(dbCon, dbCursor):
    accNo = input('Enter accNo to delete: ')
    count = bankDb.deleteAccFromDb(dbCon, dbCursor, accNo)
    if count == 1:
        print('Successfully deleted account.')
    else:
        print('Failed to delete account. accNo =', accNo)


def transact(dbCon, dbCursor):
    accNo = input('Enter accNo to transact: ')
    data = bankDb.fetchAccDetailsFromDb(dbCursor, accNo)
    if data != None:
        print('ACCOUNT DETAILS')
        print('(accno, acctype, accname, prmcustid, jtcustid, ' +
              'createdate, updatedate, balance)')
        print(data)
        type = int(input('Select type of transaction ' +
                         '(1. Withdraw 2. Deposit): '))
        amount = float(input('Enter amount: '))
        balance = float(data[7])
        if type == 1:
            if amount > data[7]:
                print('Withdraw error, Insufficient balance.')
                return False
            else:
                balance -= amount
        elif type == 2:
            balance += amount
        updateDt = input('  Update date (YYYY-MM-DD)?')
        count = bankDb.updateAccInDb(dbCon, dbCursor, accNo, balance,
                                     updateDt)
        if count == 1:
            print('Transaction successful.')
            return True
        else:
            print('Transaction failed.')
            return False
    else:
        print('Account NOT found.accNo =', accNo)
        return False


print('**************************')
print('* BANK MANAGEMENT SYSTEM *')
print('**************************')

CORRECT_USER_NAME = 'maharnab'
CORRECT_PASSWORD = 'maharnab'

print('ENTER CREDENTIALS TO LOG IN TO THE SYSTEM')
print('(Maximum 3 login attempts are allowed)\n')

userName = ''
password = ''

for i in range(3):  # Should fail after 3 login attempts
    userName = input('Enter the user name: ')
    password = input(f'Enter the password for {userName}: ')
    if userName != CORRECT_USER_NAME or password != CORRECT_PASSWORD:
        print('> ERROR: Wrong user name or password!')
        print('> Remaining', 3-i-1, 'attempts!')
    else:
        print('> Credentials verified successfully...')
        break
else:
    print('> Failed to login! EXIT!')
    quit()

# connect to mysql
print('> Initiailizing bank management system...')
print('> Logging into the database...')
dbCon, dbCursor = bankDb.connectToDb(userName, password)
if dbCon == None:
    print('>Failed to log into the database. EXIT')
    # quit
else:
    print(' Successfully logged into the database...')


bankDb.createDb(dbCon, dbCursor)

print('> Checking accounts table...')
accountTableName = 'bank_accs'
existingAccs = bankDb.createAccTable(dbCon, dbCursor)
print(f'> Found details of {existingAccs} accounts...')
print('> Checking customer table...')
customerTableName = 'bank_custs'
existingCusts = bankDb.createCustTable(dbCon, dbCursor)
print(f'> Found details of {existingCusts} customers...')

# menu starts
choice = 0
while choice != 6:
    displayMenu()
    choice = int(input('>>> Enter your choice [1-6]: '))
    if choice == 1:
        newCustomer(dbCon, dbCursor)
    elif choice == 2:
        openBankAcc(dbCon, dbCursor)
    elif choice == 3:
        getAccDetails(dbCursor)
    elif choice == 4:
        deleteAcc(dbCon, dbCursor)
    elif choice == 5:
        transact(dbCon, dbCursor)
    elif choice == 6:
        print('Bye!')
        bankDb.closeDbConnection(dbCon, dbCursor)
    else:
        print('Invalid choice. Select right operation.')
        choice = 0
