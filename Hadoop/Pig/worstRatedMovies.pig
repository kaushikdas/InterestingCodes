/**
 * Create a _relation_ named ratings by loading file u.data file from
 * *HDFS*. Pig by default expects the file to be TAB delimited and
 * this file is already TAB delimited.
 * The relation is created with the schema that is specified during
 * reading the file from HDFS and by assigning name and type to each
 * field as specified by the schema description.
 **/
ratings = LOAD '/user/maria_dev/ml-100k/u.data' -- this is path from HDFS
     AS (userID:int, movieID:int, rating:int, ratingTime:int);

metaData = LOAD '/user/maria_dev/ml-100k/u.item'
    USING PigStorage('|') -- because this file uses | as delim
    AS (movieID:int, movieTitle:chararray, releaseDate:chararray,
        videoRelease:chararray, imdbLink:chararray);

nameLookup = FOREACH metaData GENERATE movieID, movieTitle, releaseDate,
        ToUnixTime(ToDate(releaseDate, 'dd-MMM-yyyy')) AS releaseEpoch;

ratingsByMovie = GROUP ratings BY movieID;

avgRatings = FOREACH ratingsByMovie
    GENERATE group AS movieID,    -- group is the a new column name
             AVG(ratings.rating) AS avgRating,
             COUNT(ratings.rating) AS ratingCount;

-- consider movies rated by at least 10 viewers
worstMovies = FILTER avgRatings
    BY (avgRating < 2.0 AND ratingCount > 10);

worstMoviesWithData = JOIN worstMovies BY movieID, nameLookup BY movieID;

sortedResult = ORDER worstMoviesWithData
    BY worstMovies::ratingCount DESC, nameLookup::releaseEpoch ASC;

oldestWorstMovies = FOREACH sortedResult
    GENERATE worstMovies::movieID as movieID,
        nameLookup::movieTitle as movieTitle,
        nameLookup::releaseDate as releaseDate,
        worstMovies::avgRating as avgRating,
        worstMovies::ratingCount as ratingCount;

finalResult = LIMIT oldestWorstMovies 10;

DUMP finalResult;

STORE finalResult INTO '/user/maria_dev/pig_Output/' USING PigStorage (',');

-- :~~~~~~~~~~
-- :~ OUTPUT ~
-- :~~~~~~~~~~

/**
 * DUMPED FILE CONTENT
 *
 * 901,Mr. Magoo (1997),25-Dec-1997,1.9166666666666667,12
 * 688,Leave It to Beaver (1997),22-Aug-1997,1.8409090909090908,44
 * 457,Free Willy 3: The Rescue (1997),08-Aug-1997,1.7407407407407407,27
 * 1254,Gone Fishin' (1997),30-May-1997,1.8181818181818181,11
 * 894,Home Alone 3 (1997),01-Jan-1997,1.894736842105263,19
 * 890,Mortal Kombat: Annihilation (1997),01-Jan-1997,1.9534883720930232,43
 * 743,Crow: City of Angels, The (1996),30-Aug-1996,1.9487179487179487,39
 * 976,Solo (1996),23-Aug-1996,1.8333333333333333,12
 * 1215,Barb Wire (1996),03-May-1996,1.9333333333333333,30
 * 103,All Dogs Go to Heaven 2 (1996),29-Mar-1996,1.8666666666666667,15
 */
