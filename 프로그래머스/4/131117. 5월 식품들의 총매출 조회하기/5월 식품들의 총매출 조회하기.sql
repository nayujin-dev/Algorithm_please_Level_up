-- 코드를 입력하세요
SELECT p.product_id, p.product_name, o.tot_amount*p.price as total_sales
from food_product p
join (
    select product_id,sum(amount) as tot_amount
    from food_order
    where to_char(produce_date,'yyyymm') = '202205'
    group by product_id) o
on p.product_id = o.product_id
order by total_sales desc, p.product_id asc;