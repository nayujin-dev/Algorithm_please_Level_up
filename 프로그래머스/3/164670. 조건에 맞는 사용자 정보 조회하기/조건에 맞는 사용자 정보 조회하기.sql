-- 코드를 입력하세요
SELECT u.user_id, u.nickname, u.city||' '||u.street_address1||' '||u.street_address2 as 전체주소, substr(u.tlno,1,3)||'-'||substr(u.tlno,4,4)||'-'||substr(u.tlno,8,4) as 전화번호
from used_goods_user u, (
    select writer_id, count(writer_id)
    from used_goods_board
    group by writer_id
    having count(writer_id) >=3
    ) b
where b.writer_id = u.user_id
order by u.user_id desc;
