-- link https://leetcode-cn.com/problems/customers-who-never-order/
select
  Name as Customers
from
  Customers
where
  Id not in (
    select
      CustomerId
    from
      Orders
  )