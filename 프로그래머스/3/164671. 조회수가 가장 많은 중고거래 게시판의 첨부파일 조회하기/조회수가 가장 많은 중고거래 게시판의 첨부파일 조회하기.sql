-- 코드를 입력하세요
SELECT '/home/grep/src/'
    || f.board_id || '/' 
    || f.file_id
    || f.file_name 
    || f.file_ext
    as FILE_PATH
from USED_GOODS_FILE f, (
    select *
    from (
        select board_id
        from USED_GOODS_BOARD
        order by views desc
    ) 
    where rownum<=1
) b
where f.board_id = b.board_id
order by FILE_PATH desc;