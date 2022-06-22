-- Title and release year of all HP movies, ordered chronologically
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter and%' ORDER BY year ASC;
