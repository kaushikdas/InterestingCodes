from pyspark import SparkConf, SparkContext

'''
This function just creates a Python dictionary that we use later to convert
movie ID's to movie names while printing the final result
'''
def loadMovieNames():
    movieNames = {}
    with open('ml-100k/u.item') as f:
        for line in f:
            fields = line.split('|')
            movieNames[int(fields[0])] = fields[1]
    return movieNames

'''
This function takes each line of u.data and converts that to 
(movieID, (rating, 1.0)). This way we can then add up all the ratings for
each movie and the total number of ratings for each (which lets
up compute the average)
'''
def parseInput(line):
    fields = line.split()
    return (int(fields[1]), (float(fields[2]), 1.0)) # 1.0 is the freq of this rating

# The main function
def main():
    '''
    Using SparkConf we can configure how the job will distributed or how much 
    RAM the executor     should have, etc. But for now let us just set the 
    application name. We can see the     application in the below given name 
    in Ambari.
    '''
    conf = SparkConf().setAppName('WorstMovies')
    sc = SparkContext(conf=conf) # Create our Spark context

    # Load uo movieID -> movie name lookup table
    movieNames = loadMovieNames()

    # Load up the raw u.data file
    lines = sc.textFile('hdfs:///user/maria_dev/ml-100k/u.data')

    # Convert to (movieID, (rating, 1.0))
    movieRatings = lines.map(parseInput)
    
    # Reduce to (movieID, (ratingTotal, ratingCount))
    ratingTotalAndFreq = movieRatings.reduceByKey(
                            lambda ratingAndFreq1, ratingAndFreq2:
                                (ratingAndFreq1[0] + ratingAndFreq2[0], 
                                 ratingAndFreq1[1] + ratingAndFreq2[1]))
    
    # Map to (movieID, averageRating)
    averageRatings = ratingTotalAndFreq.mapByValues(
                            lambda ratingSumAndFreq: 
                                ratingSumAndFreq[0] / ratingSumAndFreq[1])
                         
    # Sort by average rating
    sortedMovies = averageRatings.sortBy(lambda x: x[1])
    
    # Take the top 10 results
    results = sortedMovies.take(10)
    
    # Print top 10 (i.e., bottom 10)
    for result in results:
        print(movieNames[result[0]], result[1]) 
    

if __name__ == "__main__":
    main()
    
    
'''
SAMPLE OUTPUT

$spark-submit WorstRatedMoviesSpark.py
Multiple versions of Spark are installed by SPARK_MAJOR_VERSION is not set
Spark1 will be picked by default
('3 Ninjas: High Noon At Mega Mountain (1998)', 1.0)
('Beyond Bedlam (1993)', 1.0)
('Power 98 (1995)', 1.0)
('Bloody Child, The (1996)', 1.0)
('Amityville: Dollhouse (1996)', 1.0)
('Babyfever (1994)', 1.0)
('Homage (1995)', 1.0)
('Somebody to Love (1994)', 1.0)
('Crude Oasis, The (1995)', 1.0)
('Every Other Weekend (1990)', 1.0)

'''
