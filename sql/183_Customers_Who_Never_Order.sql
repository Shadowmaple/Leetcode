-- Write your MySQL query statement below
select Name as Customers
from Customers
where Id not in (
    select c.Id
    from Customers as c Join Orders as o
    where c.Id = o.CustomerId)
;
