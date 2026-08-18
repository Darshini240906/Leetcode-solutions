# Write your MySQL query statement below
SELECT p.name, sum(q.amount) as balance 
FROM Users p 
JOIN Transactions q
ON p.account = q.account 
GROUP BY p.account,p.name
HAVING sum(q.amount)>10000;