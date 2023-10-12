SELECT animal_type, NVL(name,'No name') as name, sex_upon_intake 
from ANIMAL_INS
order by animal_id;