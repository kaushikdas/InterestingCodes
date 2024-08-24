import mysql.connector as sqltor


def connectToDb(username, password):
    dbCon = sqltor.connect(host='localhost', user=username,
                           passwd=password)
    if dbCon.is_connected() == True:
        return (dbCon, dbCon.cursor())
    else:
        print('DB Connection error!\n')
        return (None, None)


def createDb(dbCon, dbCursor, dbName='bank_db'):
    dbCursor.execute('CREATE DATABASE IF NOT EXISTS '+dbName)
    dbCursor.execute('USE '+dbName)


def createAccTable(dbCon, dbCursor, accountTableName='bank_accs'):
    createTableQuery = f'''CREATE TABLE IF NOT EXISTS
        {accountTableName} (
            accno CHAR(10) NOT NULL PRIMARY KEY,
            acctype CHAR(4) NOT NULL,accname VARCHAR(20),
            prmcustid INT NOT NULL,jtcustid INT,
            createdate DATE,updatedate DATE,
            balance DECIMAL)'''
    dbCursor.execute(createTableQuery)
    dbCursor.execute('SELECT * FROM ' + accountTableName)
    dbCursor.fetchall()
    return dbCursor.rowcount


def createCustTable(dbCon, dbCursor, customerTableName='bank_custs'):
    createTableQuery = f'''CREATE TABLE IF NOT EXISTS 
        {customerTableName} (
            custid INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
            custname VARCHAR(30),mobile CHAR(10),
            address VARCHAR(50))'''
    dbCursor.execute(createTableQuery)
    dbCursor.execute('SELECT * FROM ' + customerTableName)
    data = dbCursor.fetchall()
    return dbCursor.rowcount


def addCustToDb(dbCon, dbCursor, name, mobile, address):
    query = f'''
       INSERT INTO bank_custs(custname,mobile,address) VALUES(
          "{name}","{mobile}","{address}")
    '''
    dbCursor.execute(query)
    dbCon.commit()
    insertedRowCount = dbCursor.rowcount
    newCustId = dbCursor.lastrowid
    return (insertedRowCount, newCustId)


def fetchCustomerDetailsFromDb(dbCursor, custid):
    query = f'SELECT * FROM bank_custs WHERE custid = {custid}'
    dbCursor.execute(query)
    data = dbCursor.fetchone()
    if (dbCursor.rowcount > 0):
        return data
    else:
        return None


def getCustomerCountFromDb(dbCursor):
    dbCursor.execute('SELECT * FROM bank_custs')
    dbCursor.fetchall()
    return dbCursor.rowcount


def getAccCountFromDb(dbCursor):
    dbCursor.execute('SELECT * FROM bank_accs')
    dbCursor.fetchall()
    return dbCursor.rowcount


def addAccToDb(dbCon, dbCursor, accNo, accType, accName,
               primCustId, jtCustId, createDate, updateDate, balance):
    query = f'''INSERT INTO bank_accs(accno,acctype,accname,prmcustid,
        jtcustid,createdate,updatedate,balance) VALUES(
        "{accNo}","{accType}","{accName}",{primCustId},{jtCustId},
        "{createDate}","{updateDate}",{balance})'''
    dbCursor.execute(query)
    dbCon.commit()
    insertedRowCount = dbCursor.rowcount
    return insertedRowCount


def fetchAccDetailsFromDb(dbCursor, accNo):
    query = f'SELECT * FROM bank_accs WHERE accno = "{accNo}"'
    dbCursor.execute(query)
    data = dbCursor.fetchone()
    if (dbCursor.rowcount > 0):
        return data
    else:
        return None


def deleteAccFromDb(dbCon, dbCursor, accNo):
    query = f'DELETE FROM bank_accs WHERE accno = "{accNo}"'
    dbCursor.execute(query)
    dbCon.commit()
    deletedRowCount = dbCursor.rowcount
    return deletedRowCount


def updateAccInDb(dbCon, dbCursor, accNo, balance, updateDt):
    query = f'''UPDATE bank_accs SET balance = {balance},
        updatedate = "{updateDt}" WHERE accno = "{accNo}"
        '''
    dbCursor.execute(query)
    dbCon.commit()
    updatedRowCount = dbCursor.rowcount
    return updatedRowCount


def closeDbConnection(dbCon, dbCursor):
    dbCursor.fetchall()
    dbCursor.close()
    dbCon.close()
    return (None, None)
