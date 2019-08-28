CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare num int;
set num = N -1;
  RETURN (
      # Write your MySQL query statement below.    
      select distinct Salary from Employee order by Salary DESC limit 1 offset num
  );
END
