-- Number of movies with 10.0 rating
SELECT COUNT(title) FROM ratings JOIN movies ON movies.id = ratings.movie_id WHERE rating = 10.0;
