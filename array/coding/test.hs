-- haskell version
import qualified Data.Set as Set

rotate_array l k = end ++ front
  where
    len = length l
    k' = k `mod` len
    (front, end) = splitAt (len - k') l

remove_dups [] = []
remove_dups (x : xs) = x : remove_dups (dropWhile (== x) xs)

merge_sorted_array [] l2 = l2
merge_sorted_array l1 [] = l1
merge_sorted_array l1@(x : xs) l2@(y : ys)
  | x < y = x : (merge_sorted_array xs l2)
  | otherwise = y : (merge_sorted_array ys l1)

intersection l1 l2 =
  let set1 = Set.fromList l1
      set2 = Set.fromList l2
   in Set.toList (Set.intersection set1 set2)
