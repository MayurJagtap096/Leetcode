SELECT 
CASE
    WHEN 
        id = (select max(id) from seat) and mod(id, 2) = 1 then id
    WHEN 
        MOD(id, 2) = 1
    THEN id + 1
    ELSE 
        id - 1
END as id, student
FROM Seat
order by id