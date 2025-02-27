-- 코드를 입력하세요
select * from (
SELECT animal_ins.name, animal_ins.datetime
from animal_ins
    left outer join animal_outs
on animal_ins.animal_id = animal_outs.animal_id(+)
where animal_outs.ANIMAL_ID IS NULL
order by animal_ins.datetime
)
WHERE ROWNUM <= 3
;