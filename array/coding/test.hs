rotate_array l k = end ++ front
  where
    len = length l
    k' = k `mod` len
    (front, end) = splitAt (len - k') l


