SELECT 
t.request_at as "Day",
ROUND(SUM(CASE when t.status='completed' then 0 else 1 end)::decimal / count(*), 2) as "Cancellation Rate"
FROM Trips t
WHERE (t.request_at BETWEEN '2013-10-01' AND '2013-10-03')
and t.client_id not in (select users_id from Users where banned::text = 'Yes')
and t.driver_id not in (select users_id from Users where banned::text = 'Yes')
group by t.request_at