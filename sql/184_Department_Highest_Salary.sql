-- Write your MySQL query statement below

select b.Name as Department, a.Name as Employee, a.Salary
from Department as b,
(
    select Name, Salary, DepartmentId
    from Employee
    where Name not in (
        select a.Name
        from Employee a, Employee b
        where a.DepartmentId = b.DepartmentId
            and a.Salary < b.Salary
    )
) as a
where b.Id = a.DepartmentId
;

-- 相对来说更优解，其实差不多，两个字段的in用法，学着点
select a.Name as Department, b.Name as Employee, b.Salary
from Department as a, (
    select DepartmentId, Salary, Name
    from Employee
    where (DepartmentId, Salary) in (
        select DepartmentId, Max(Salary)
        from Employee
        group by DepartmentId
    )
) b
where a.Id = b.DepartmentId
;


-- 思路一样，但是直接三表联结
select b.Name as Department, a.Name as Employee, a.Salary
from Employee a, Department b, (
    select DepartmentId, Max(Salary) as Salary
    from Employee
    group by DepartmentId
) c
where a.Salary = c.Salary
    and a.DepartmentId = c.DepartmentId
    and a.DepartmentId = b.Id
;

