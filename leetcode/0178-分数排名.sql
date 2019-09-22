-- link https://leetcode-cn.com/problems/rank-scores/
select
  Score,
  (
    select
      count(distinct(Score)) + 1
    from
      Scores as B
    where
      B.Score > A.Score
  ) as Rank
from
  Scores as A
order by
  Rank