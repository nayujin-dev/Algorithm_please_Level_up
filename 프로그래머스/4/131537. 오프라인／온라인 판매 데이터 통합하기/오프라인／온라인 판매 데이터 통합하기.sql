-- 코드를 입력하세요
SELECT to_char(SALES_DATE,'yyyy-mm-dd') as SALES_DATE, 
    PRODUCT_ID, USER_ID, sum(SALES_AMOUNT) SALES_AMOUNT
from (
    select product_id, user_id, sales_amount, sales_date
    from ONLINE_SALE 
    where to_char(sales_date, 'yyyymm') = '202203'
    union all
    select product_id, null as user_id, sales_amount, sales_date
    from OFFLINE_SALE  
    where to_char(sales_date, 'yyyymm') = '202203'
)
group by SALES_DATE, PRODUCT_ID, USER_ID
order by 1, 2, 3;