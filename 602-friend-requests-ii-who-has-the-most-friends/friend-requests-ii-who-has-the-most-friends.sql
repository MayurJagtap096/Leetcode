with all_friends as (
    select requester_id as user_id from RequestAccepted
    union all 
    select accepter_id as user_id from RequestAccepted
)

select user_id as id, count(*) as num from all_friends
group by user_id
order by num desc limit 1