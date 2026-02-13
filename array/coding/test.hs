import Data.List (nub)
rotate_array l k = end ++ front
  where
    len = length l
    k' = k `mod` len
    (front, end) = splitAt (len - k') l


remove_dups [] = []
remove_dups (x:xs) = x : remove_dups (dropWhile (==x) xs)
