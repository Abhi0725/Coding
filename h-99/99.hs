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


-- Problem 5

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = (reverse xs) ++ [x]

reverse_aux [] out = out
reverse_aux (x:xs) out = reverse_aux xs (x:out)
myReverse' l = reverse_aux l []


-- Problem 6

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome l = l == reverse l


