-- 코드를 입력하세요
SELECT b.category, sum(s.sales) as total_sales
from book b
left join book_sales s 
on s.book_id = b.book_id
and to_char(s.sales_date,'yyyy-mm') = '2022-01'
group by b.category
order by b.category;