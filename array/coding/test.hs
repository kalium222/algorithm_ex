-- haskell version

import Data.List (nub, sort)
import Data.Set qualified as Set

rotate_array l k = end ++ front
  where
    len = length l
    k' = k `mod` len
    (front, end) = splitAt (len - k') l

remove_dups [] = []
remove_dups (x : xs) = x : remove_dups (dropWhile (== x) xs)

merge [] l2 = l2
merge l1 [] = l1
merge l1@(x : xs) l2@(y : ys)
  | x < y = x : (merge xs l2)
  | otherwise = y : (merge ys l1)

merge_sorted_array :: (Ord a) => [a] -> [a] -> [a]
merge_sorted_array = merge

merge_sort :: (Ord a) => [a] -> [a]
merge_sort [] = []
merge_sort l =
  let half = length l `div` 2
      (l1, l2) = splitAt half l
   in merge_sort l1 `merge` merge_sort l2

quick_sort [] = []
quick_sort (x : xs) =
  let smallers = [a | a <- xs, a <= x]
      largers = [a | a <- xs, a > x]
   in -- NOTE: use `filter`
      quick_sort smallers ++ [x] ++ quick_sort largers

intersection l1 l2 =
  let set1 = Set.fromList l1
      set2 = Set.fromList l2
   in Set.toList (Set.intersection set1 set2)

intersection' :: (Ord a) => [a] -> [a] -> [a]
intersection' l1 l2 =
  let sorted_l1 = nub . sort $ l1
      sorted_l2 = nub . sort $ l2
   in -- NOTE: this is fucking O(nm)
      -- in foldr (\a acc -> if a `elem` sorted_l1 then a : acc else acc) [] sorted_l2
      intersect_sorted sorted_l1 sorted_l2
  where
    intersect_sorted [] _ = []
    intersect_sorted _ [] = []
    intersect_sorted l1@(x : xs) l2@(y : ys)
      | x > y = intersect_sorted l1 ys
      | x == y = x : intersect_sorted xs ys
      | otherwise = intersect_sorted xs l2
