-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

-- First select movie titles where Johnny Depp has starred
SELECT movies.title FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Johnny Depp'

INTERSECT

SELECT movies.title FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Helena Bonham Carter';
