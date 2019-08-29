-- Write your MySQL query statement below

select distinct a.Num as ConsecutiveNums
from Logs a, Logs b, Logs c
where a.Num = b.Num
    and b.Num = c.Num
    and a.Id = b.Id + 1
    and b.Id = c.Id + 1
;    


-- 更优更合理的方法
select distinct a.Num as ConsecutiveNums
from (
    select
        Num,
        @count := if(@pre = Num, @count + 1, 1) as count,
        @pre := Num as pre
    from (
        Logs, (select @count := 0, @pre := null) as b
    )
) as a
where a.count >= 3
;

