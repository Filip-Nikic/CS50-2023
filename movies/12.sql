SELECT movies.title FROM stars JOIN people ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id WHERE people.name='Jennifer Lawrence' AND movies.id IN (SELECT movies.id FROM movies, stars, people WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND people.name='Bradley Cooper');