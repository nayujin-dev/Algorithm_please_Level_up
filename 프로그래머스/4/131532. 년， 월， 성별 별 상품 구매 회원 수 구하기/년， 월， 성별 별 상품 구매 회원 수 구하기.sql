-- 코드를 입력하세요
SELECT s.year, to_number(s.month) month, u.gender, count(distinct u.user_id) USERS
from USER_INFO u, (
    select user_id, to_char(sales_date,'yyyy') year, to_char(sales_date,'mm') month
    from ONLINE_SALE
) s
where u.user_id = s.user_id and u.gender is not null
group by u.gender, s.year, s.month
having u.gender is not null
order by s.year, to_number(s.month), u.gender