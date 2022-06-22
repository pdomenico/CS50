--  write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
SELECT name FROM ratings
JOIN movies ON movies.id = ratings.movie_id
JOIN directors ON directors.movie_id = movies.id
JOIN people ON people.id = directors.person_id
WHERE rating >= 9.0;
