-- 코드를 입력하세요
SELECT
    history_id, 
    car_id, 
    to_char(start_date,'yyyy-mm-dd') START_DATE, 
    to_char(end_date,'yyyy-mm-dd') END_DATE, 
    case when end_date-start_date >= 29 
    then '장기 대여'
    else '단기 대여'
    end rent_type
from car_rental_company_rental_history
where to_char(start_date, 'yyyy-mm') = '2022-09'
order by history_id desc;