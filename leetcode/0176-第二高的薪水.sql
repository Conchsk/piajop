-- link https://leetcode-cn.com/problems/second-highest-salary/
select max(Salary) as SecondHighestSalary from Employee where Salary not in (select max(Salary) from Employee)
