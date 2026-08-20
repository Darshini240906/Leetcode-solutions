SELECT DISTINCT t1.num AS ConsecutiveNums
FROM Logs t1
JOIN Logs t2 ON t1.id + 1 = t2.id
JOIN Logs t3 ON t2.id + 1 = t3.id
WHERE t1.num = t2.num AND t2.num = t3.num;
