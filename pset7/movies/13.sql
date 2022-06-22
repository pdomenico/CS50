-- List the name of the people which starred in movies in which Kevin Bacon starred
select name from people
join stars on stars.person_id = people.id
join movies on movies.id = stars.movie_id
where movie_id IN

(select movies.id from movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
where name = 'Kevin Bacon');
