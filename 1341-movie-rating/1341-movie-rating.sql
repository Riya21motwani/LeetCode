# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating m
JOIN Users u
ON m.user_id=u.user_id
GROUP BY u.user_id
ORDER BY COUNT(*) DESC, u.name ASC
LIMIT 1)
UNION ALL
(SELECT m.title
FROM MovieRating r
JOIN Movies m
ON m.movie_id=r.movie_id
WHERE r.created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY r.movie_id
ORDER BY AVG(r.rating) DESC,m.title ASC
LIMIT 1)