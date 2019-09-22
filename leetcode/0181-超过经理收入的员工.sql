-- link https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/
select
  A.Name as Employee
from
  Employee A,
  Employee B
where
  A.ManagerId is not NULL
  and A.ManagerId = B.Id
  and A.Salary > B.Salary