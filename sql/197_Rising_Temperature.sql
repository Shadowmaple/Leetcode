-- Write your MySQL query statement below
select w1.Id as Id
from Weather w1, Weather w2
where datediff(w1.RecordDate, w2.RecordDate) = 1 
	and w1.temperature > w2.temperature
;
