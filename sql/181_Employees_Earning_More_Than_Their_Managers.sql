-- 854ms，子查询
select e.Name as Employee
    from Employee as e
    where e.Salary > (select m.Salary from Employee as m
					where m.Id = e.ManagerId)
    ;


-- 更优的题解，使用表联结，506ms
/*
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
;
*/
