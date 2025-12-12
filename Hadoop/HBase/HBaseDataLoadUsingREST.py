# Before running this code start the HBase REST service
# # /usr/hdp/current/hbase-master/bin/hbase-daemon.sh start rest -p 8000 --info-port 8001
# ... and once finished we can stop the REST service
# # /usr/hdp/current/hbase-master/bin/hbase-daemon.sh stop rest

from starbase import Connection

HBASE_HOST = '127.0.0.1'
HBASE_PORT = '8080'

HBASE_TABLE = 'kaushik:rating'
COLUMN_FAMILY = 'rating'

RATINGS_FILE = 'C:/u.data'

# In this case we can even skip mentioning the host & port
# ... because if none are specified by default the values
# ... 127.0.0.1 and 8000 are taken as host and port, respectively
conn = Connection(HBASE_HOST, HBASE_PORT)

movieRatingsTable = conn.table(HBASE_TABLE)

if (movieRatingsTable.exists()):
    print('Dropping existing movie ratings table\n')
    movieRatingsTable.drop()

# Create fresh table
movieRatingsTable.create(COLUMN_FAMILY)

# Create a batch to push data to HBase table in batch mode
batch = movieRatingsTable.batch()

with open(RATINGS_FILE) as f:
    for line in f:
        (userId, movieId, rating, timestamp) = line.split()
        batch.update(userId, {COLUMN_FAMILY: {movieId : rating}})

# Commit ratings data to HBase table
print('Commit ratings data to HBase table...\n')
batch.commit(finalize=True)

# Read some records back from the HBase table
print('Reading records from HBase table...\n')
print('Ratings for user is 15\n')
print(movieRatingsTable.fetch('15'))
print('Ratings for user is 30\n')
print(movieRatingsTable.fetch('30'))