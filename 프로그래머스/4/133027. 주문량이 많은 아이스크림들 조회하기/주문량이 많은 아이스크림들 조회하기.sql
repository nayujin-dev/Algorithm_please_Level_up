-- 코드를 입력하세요
select flavor
from (
    select flavor, sum(total_order) as total_order
    from(
        SELECT flavor, sum(total_order) as total_order
        from FIRST_HALF
        group by flavor
        union all
        SELECT flavor, sum(total_order) as total_order
        from JULY
        group by flavor
    )
    group by flavor
    order by total_order desc  
)
where rownum<=3;

