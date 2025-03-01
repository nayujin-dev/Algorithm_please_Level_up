-- 코드를 입력하세요
SELECT i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, 
    r.review_score as SCORE
from REST_INFO i,
    ( select rest_id, round(avg(review_score),2) as review_score
      from REST_REVIEW
      group by rest_id
    ) r
where i.rest_id = r.rest_id and i.address like '서울%'
order by SCORE desc, i.favorites desc;