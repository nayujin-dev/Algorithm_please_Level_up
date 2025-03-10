-- 코드를 입력하세요
SELECT u.user_id, u.nickname, sum(b.price) as total_salses
from used_goods_user u, used_goods_board b
-- left join used_goods_board b
-- on u.user_id = b.writer_id
where u.user_id = b.writer_id and b.status = 'DONE'
group by u.user_id, u.nickname
having sum(b.price) >= 700000
order by 3;