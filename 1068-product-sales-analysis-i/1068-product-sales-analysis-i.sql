# Write your MySQL query statement below

SELECT product_name,year,price
FROM Sales AS s
LEFT JOIN 
product AS P
ON p.product_id=s.product_id
