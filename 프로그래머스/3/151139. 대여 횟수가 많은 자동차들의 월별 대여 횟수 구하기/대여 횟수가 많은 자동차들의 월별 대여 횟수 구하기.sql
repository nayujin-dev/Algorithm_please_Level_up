-- 코드를 입력하세요
SELECT to_number(to_char(start_date,'mm')) as MONTH, CAR_ID, count(CAR_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between to_date('20220801','yyyymmdd') and to_date('20221031','yyyymmdd')
    group by car_id
    having count(car_id) >= 5
) and start_date between to_date('20220801','yyyymmdd') and to_date('20221031','yyyymmdd')
group by to_number(to_char(start_date,'mm')), CAR_ID
having count(CAR_ID) > 0
order by 1, 2 desc;