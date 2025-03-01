-- 코드를 입력하세요
SELECT a.apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from appointment a, doctor d, patient p
where 
    p.pt_no=a.pt_no and 
    a.mddr_id = d.dr_id and 
    to_char(a.apnt_ymd,'yyyymmdd')='20220413' and 
    a.apnt_cncl_yn='N'
order by a.apnt_ymd;