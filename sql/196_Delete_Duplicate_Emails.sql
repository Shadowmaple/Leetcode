-- Write your MySQL query statement below
-- 自联结，1104ms
delete p1 from Person as p1, Person as p2
where p1.Email = p2.Email and p1.Id > p2.Id;


-- 更优解，913ms，击败92.7%

DELETE FROM Person
WHERE Id NOT IN (   -- 删除不在查询结果中的值
    SELECT id FROM
   (
       SELECT MIN(Id) AS Id -- 排除Email相同时中Id较大的行
       FROM Person
       GROUP BY Email
   ) AS temp    -- 此处需使用临时表，否则会发生报错
)
;

