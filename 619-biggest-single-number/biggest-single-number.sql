-- Write your PostgreSQL query statement below

WITH UNIQUE_NUMS AS (
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING count(*) = 1
)
SELECT MAX(un.num) AS num FROM UNIQUE_NUMS un