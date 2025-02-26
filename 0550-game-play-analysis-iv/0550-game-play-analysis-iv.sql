# Write your MySQL query statement below

-- | player_id | device_id | event_date | games_played |
-- | --------- | --------- | ---------- | ------------ |
-- | 1         | 2         | 2016-03-01 | 5            |
-- | 1         | 2         | 2016-03-02 | 6            |
-- | 2         | 3         | 2017-06-25 | 1            |
-- | 3         | 1         | 2016-03-02 | 0            |
-- | 3         | 4         | 2018-07-03 | 5            |


WITH FirstLogin AS (
    SELECT player_id, MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
NextDayLogin AS (
    SELECT DISTINCT a.player_id
    FROM Activity a
    JOIN FirstLogin f
    ON a.player_id = f.player_id
    WHERE a.event_date = DATE_ADD(f.first_login_date, INTERVAL 1 DAY)
)
SELECT ROUND(COUNT(DISTINCT n.player_id) / COUNT(DISTINCT f.player_id), 2) AS fraction
FROM FirstLogin f
LEFT JOIN NextDayLogin n
ON f.player_id = n.player_id;
