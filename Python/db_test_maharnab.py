import mysql.connector as cnx

def connect_dbms():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')
    conn.close()
        
def create_database():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')
        
    cur = conn.cursor()
    db_name = 'hello_db'
    cur.execute(f'CREATE DATABASE IF NOT EXISTS {db_name}')
    
    cur.close()
    conn.close()
    
def create_table():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')
        
    cur = conn.cursor()
    db_name = 'hello_db'
    cur.execute(f'USE {db_name}')
    table_name = 'books'
    query = f'CREATE TABLE IF NOT EXISTS {table_name}(id INT PRIMARY KEY, name VARCHAR(10), authors varchar(20))'
    cur.execute(query)
    
    cur.close()
    conn.close()

def add_books():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab',
                       database='hello_db')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')

    books = [
          (1, 'Physics', 'H C Verma'),
          (2, 'Chemistry', 'J D Lee')
        #   [3, 'Algebra', 'S L Loney'],
        #   [4, 'Geometry', 'S L Loney']
        ]

    cur = conn.cursor()

    for book in books:
        qs = "INSERT INTO books(id, name, authors) VALUES(%s, %s, %s)"
        print(qs)
        cur.execute(qs, book)

    conn.commit()
    
    cur.close()
    conn.close()

def fetch_books():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab',
                       database='hello_db')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')

    cur = conn.cursor()

    qs = 'SELECT * FROM BOOKS'
    cur.execute(qs)
    result = cur.fetchall()

    for r in result:
        print(r)    
    
    cur.close()
    conn.close()    

    
def drop_table():
    conn = cnx.connect(host='localhost', user='maharnab', passwd='maharnab',
                       database='hello_db')

    if conn.is_connected() == True:
        print('DBMS connection successful')
    else:
        print('FAILURE')
        
    cur = conn.cursor()
    table_name = 'world_table'
    cur.execute(f'DROP TABLE IF EXISTS {table_name}')
    
    cur.close()
    conn.close()
        
add_books()
