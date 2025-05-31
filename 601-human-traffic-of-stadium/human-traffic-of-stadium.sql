WITH filtered AS (
  SELECT *
  FROM Stadium
  WHERE people >= 100
),
tagged AS (
  SELECT *,
         LAG(id, 1) OVER (ORDER BY id) AS prev_id,
         LAG(id, 2) OVER (ORDER BY id) AS prev2_id,
         LEAD(id, 1) OVER (ORDER BY id) AS next_id,
         LEAD(id, 2) OVER (ORDER BY id) AS next2_id
  FROM filtered
)
SELECT id, visit_date, people
FROM tagged
WHERE 
  (prev_id = id - 1 AND prev2_id = id - 2) OR
  (next_id = id + 1 AND next2_id = id + 2) OR
  (prev_id = id - 1 AND next_id = id + 1)
ORDER BY visit_date;
