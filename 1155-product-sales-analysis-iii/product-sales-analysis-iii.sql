-- Write your PostgreSQL query statement below
WITH sub as (
select product_id, min(year) as first_year from Sales
group by product_id 
)
select sub.product_id, sub.first_year, t.quantity, t.price from sub 
JOIN Sales t on sub.product_id = t.product_id
and sub.first_year = t.year