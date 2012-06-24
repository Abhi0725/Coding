-- Solutions to H-99: Ninety-Nine Haskell Problems
-- http://www.haskell.org/haskellwiki/99_questions

-- Problem 1

myLast :: [a] -> a
myLast [x] = x
myLast (_:xs) = myLast xs

myLast' l = l !! (length l - 1)
myLast'' l = head (reverse l)
--myLast''' l = head . reverse


-- Problem 2

--myButLast :: [a] -> a
myButLast' = head . tail . reverse
myButLast'' l = l !! (length l - 2)


-- Problem 3

elementAt :: (Num b) => [a] -> b -> a
elementAt (x:_) 1 = x
elementAt (_:xs) n = elementAt xs (n-1)


-- Problem 4

myLength :: (Num b) => [a] -> b
myLength [] = 0
myLength (_:xs) = 1 + myLength xs
myLength' l = sum [1 | _ <- l]


-- Problem 5

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = (reverse xs) ++ [x]

myReverse' l =
  reverse_aux l []
  where reverse_aux [] out = out
        reverse_aux (x:xs) out = reverse_aux xs (x:out)


-- Problem 6

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome l = l == reverse l


-- Problem 7
-- TODO: I still needs to learn how to define new types


-- Problem 8

compress :: (Eq a) => [a] -> [a]
compress [] = []
compress (x:y:xs)
  | x == y = compress (y:xs)
compress (x:xs) = x : compress xs


-- Problem 9

pack :: (Eq a) => [a] -> [[a]]
pack = pack_aux []
  where pack_aux [] [] = []
        pack_aux bucket [] = [bucket]
        pack_aux bucket (x:y:xs)
          | x == y    = pack_aux (x:bucket) (y:xs)
          | otherwise = (x:bucket) : pack_aux [] (y:xs)
        pack_aux bucket [x] = [x:bucket]