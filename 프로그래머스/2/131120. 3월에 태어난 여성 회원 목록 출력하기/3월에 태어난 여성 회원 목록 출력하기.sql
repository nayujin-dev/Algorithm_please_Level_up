-- 코드를 입력하세요
SELECT member_id "MEMBER_ID", member_name "MEMBER_NAME", gender "GENDER", to_char(date_of_birth,'yyyy-mm-dd') "DATE_OF_BIRTH"
from member_profile
where to_char(extract(month from date_of_birth))='3' and tlno is not null and gender='W'
order by member_id asc;