-- 코드를 입력하세요
SELECT distinct cart_id
from cart_products
where (cart_id, 'Milk') in (
    select cart_id, name   
    from cart_products
) and (cart_id, 'Yogurt') in (
    select cart_id, name   
    from cart_products
)
order by cart_id;