-- 코드를 입력하세요
SELECT order_id, product_id, to_char(out_date,'yyyy-mm-dd') as out_date,
    case 
        when out_date is null then '출고미정'
        when out_date <= to_date('20220501','yyyymmdd') then '출고완료'
        when out_date > to_date('20220501','yyyymmdd') then '출고대기'
        END AS 출고여부
from food_order
order by order_id;