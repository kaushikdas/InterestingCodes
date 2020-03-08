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

nameLookup = FOREACH metaData GENERATE movieID, movieTitle,
        ToUnixTime(ToDate(releaseDate, 'dd-MMM-yyyy')) AS releaseTime;

ratingsByMovie = GROUP ratings BY movieID;

avgRatings = FOREACH ratingsByMovie 
    GENERATE group AS movieID,    -- group is the a new column name
             AVG(ratings.rating) AS avgRating;

fiveStarMovies = FILTER avgRatings BY avgRating > 4.0;

fiveStarsWithData = JOIN fiveStarMovies BY movieID, nameLookup BY movieID;

oldestFiveStarMovies = ORDER fiveStarsWithData BY nameLookup::releaseTime;

DUMP oldestFiveStarMovies;
