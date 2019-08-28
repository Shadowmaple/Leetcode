select e.Name as Employee
    from Employee as e
    where e.Salary > (select m.Salary from Employee as m
					where m.Id = e.ManagerId)
    ;
