import Data.IntMap qualified as Map

subArraySum :: [Int] -> Int -> Int
subArraySum l k = go l 0 (Map.singleton 0 1) 0
  where
    go :: [Int] -> Int -> Map.IntMap Int -> Int -> Int
    go [] _ _ res = res
    go (x : xs) prefix_sum m res =
      let prefix_sum' = prefix_sum + x
          found = Map.lookup (prefix_sum' - k) m
          res' = case found of
            Nothing -> res
            Just value -> res + value
          m' = Map.insertWith (+) prefix_sum' 1 m
       in go xs prefix_sum' m' res'

findMaxLength :: [Int] -> Int
findMaxLength l = go l ind prefix_sum (Map.singleton (-1) (-1)) res
  where
    prefix_sum = 0
    ind = 0
    res = 0
    go :: [Int] -> Int -> Int -> Map.IntMap Int -> Int -> Int
    go [] _ _ _ res = res
    go (x : xs) ind prefix_sum m res =
      let prefix_sum_ = prefix_sum + x
          temp = ind - 2 * prefix_sum_
          found = Map.lookup temp m
          (res_, m_) = case found of
            Nothing -> (res, Map.insert temp ind m)
            Just value -> (max res (ind - value), m)
       in go xs (ind + 1) prefix_sum_ m_ res_
