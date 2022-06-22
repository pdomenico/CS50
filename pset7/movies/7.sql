-- List title and rating of all the movies released in 2010, in descending order by rating, alphabetically
SELECT title, rating FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE year = 2010 ORDER BY rating desc, title;
