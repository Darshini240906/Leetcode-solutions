# Write your MySQL query statement below

SELECT
    ROUND(
        COUNT(DISTINCT a1.player_id) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity a1
LEFT JOIN (
    SELECT
        player_id,
        MIN(event_date) AS fd
    FROM Activity
    GROUP BY player_id
) a2
ON a1.player_id = a2.player_id
WHERE DATEDIFF(a1.event_date, a2.fd) = 1;