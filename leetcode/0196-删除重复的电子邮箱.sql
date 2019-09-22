-- link https://leetcode-cn.com/problems/delete-duplicate-emails/
delete from
  Person
where
  Id in (
    select
      Id
    from
      (
        select
          A.Id
        from
          Person as A,
          Person as B
        where
          A.Email = B.Email
          and A.Id > B.Id
      ) as C
  )