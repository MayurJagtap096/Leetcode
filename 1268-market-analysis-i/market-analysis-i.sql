-- Write your PostgreSQL query statement below
with cte as (
    select u.user_id, count(*) as cnt from Users u
    join Orders o on u.user_id = o.buyer_id
    where o.order_date >= '2019-01-01'
    and o.order_date <= '2019-12-31'
    group by u.user_id
)
select u.user_id as buyer_id, 
u.join_date as join_date,
COALESCE(cte.cnt, 0) as orders_in_2019
from Users u
left join cte on u.user_id = cte.user_id
