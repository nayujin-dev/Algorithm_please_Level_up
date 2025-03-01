-- 코드를 입력하세요
SELECT o.animal_id, o.animal_type, o.name
from animal_ins i
left join animal_outs o
on i.animal_id = o.animal_id
where i.sex_upon_intake LIKE 'Intact%' and o.sex_upon_outcome NOT LIKE 'Intact%'
order by o.animal_id;