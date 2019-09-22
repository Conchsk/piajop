-- link https://leetcode-cn.com/problems/department-highest-salary/
select
  A.Name as Department,
  B.Name as Employee,
  B.Salary
from
  Department as A,
  Employee as B
where
  A.Id = B.DepartmentId
  and B.Id in (
    select
      Id
    from
      Employee as C,
      (
        select
          DepartmentId,
          max(Salary) as Salary
        from
          Employee
        group by
          DepartmentId
      ) as D
    where
      C.DepartmentId = D.DepartmentId
      and C.Salary = D.Salary
  )