-- 코드를 입력하세요
SELECT p.product_code, sum(o.sales_amount*p.price) as sales
from product p, offline_sale o
where p.product_id = o.product_id
group by p.product_code
order by sales desc, p.product_code;