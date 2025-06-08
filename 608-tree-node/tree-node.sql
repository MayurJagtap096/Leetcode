-- Write your PostgreSQL query statement below

select id, 
    case 
        when id = (select t1.id from Tree t1 where t1.p_id is null) then 'Root'
        when id IN (select t1.p_id from Tree t1 where t1.p_id is not null) then 'Inner'
        else 'Leaf'
    end as type
    from Tree