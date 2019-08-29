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

