# Write your MySQL query statement below

SELECT e.name
FROM Employee e
INNER JOIN Employee m
ON e.id=m.managerId
GROUP BY e.id
HAVING COUNT(m.Id)>=5

