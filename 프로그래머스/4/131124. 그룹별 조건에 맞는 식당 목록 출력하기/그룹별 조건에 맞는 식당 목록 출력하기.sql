-- 코드를 입력하세요
SELECT p.MEMBER_NAME, r.REVIEW_TEXT, to_char(r.REVIEW_DATE,'yyyy-mm-dd') as REVIEW_DATE
from MEMBER_PROFILE p, REST_REVIEW r
where p.member_id = r.member_id 
    and p.member_id in
        (select member_id
         from (
               select member_id, count(*) as tot
               from REST_REVIEW
               group by member_id
               order by tot desc
         )
         where rownum<=1
        ) 
order by 3,2
;