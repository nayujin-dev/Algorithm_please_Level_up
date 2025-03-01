-- 코드를 입력하세요
SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, sum(s.sales*b.price) as TOTAL_SALES
from BOOK b, AUTHOR a, (
    select book_id, sum(sales) as sales
    from BOOK_SALES
    where to_char(sales_date,'yyyymm')='202201'
    group by book_id
) s
where b.book_id=s.book_id and b.author_id = a.author_id
group by a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY
order by a.author_id, b.category desc;


