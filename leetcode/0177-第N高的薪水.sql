-- link https://leetcode-cn.com/problems/nth-highest-salary/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare a int;
  set a = N - 1;
  RETURN (
    # Write your MySQL query statement below.
    select distinct(Salary) from Employee order by Salary desc limit a, 1
  );
END