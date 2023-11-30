myLast :: [a] -> a
myLast [a] = a
myLast (a:b) = myLast ( drop 1 (a:b))

myInit :: [a] -> [a]
myInit [a] = []
myInit (a:b) =  take (length (a:b) - 1) (a:b)

myInv :: [a] -> [a]
myInv [a] = [a]
myInv [] = []
myInv (a:b) =  myInv b ++ [a]

myZip :: [a] -> [b] -> [(a,b)]
myZip (a:b)(c:d) = (a,c): myZip b d
myZip _ _ = []

eliminaPrimi :: [a] -> Int -> [a]
eliminaPrimi a 0 = a
eliminaPrimi (a:b) c = eliminaPrimi b (c-1)

concatena :: [a] -> [a] -> [a]
concatena [] b = b
concatena (a:b) c = a : (concatena b c)

main :: IO()
main = do
    print (myLast [2,34,3]);
    print (myInit [1,3,4])
    print (myInv [1,2,3])
    print (myZip [1,2,3]['a','b'])
    print (concatena [1,2,3][4,5,6])