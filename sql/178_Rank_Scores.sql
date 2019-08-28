-- 先进行去重，再对去重的表排序获取序号，最后再与原表联结，269ms

select s1.Score, s2.Rank
from Scores as s1,  
(
	select Score, @rank := @rank + 1 as Rank 
    from (
		select distinct Score from Scores
	) as s, 
	(
		select @rank := 0
	) as r
	order by Score desc
) as s2
where s1.Score = s2.Score
order by Score desc
;


-- 另一种方法，根据分数大小计算排名序号，较简单，但效率低，818ms
select Score,  (
    select count(distinct s2.Score)  as Rank
    from Scores as s2
    where s2.Score >= s1.Score
) as Rank
from Scores as s1
order by Score desc
;

