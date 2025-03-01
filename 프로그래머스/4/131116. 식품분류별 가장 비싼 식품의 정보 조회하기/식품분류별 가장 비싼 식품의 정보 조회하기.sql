-- 코드를 입력하세요
SELECT category, price as MAX_PRICE, product_name
from food_product 
where (category, price) in
(
    select category, max(price)
    from food_product
    where category = '과자' or category = '국' or category = '김치' or category = '식용유'
    group by category
) 
order by 2 desc;