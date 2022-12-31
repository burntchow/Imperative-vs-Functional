-- Aveline Villaganas, #026858375
-- CECS 342, Section 3 
-- Assignment 1 
-- Due 9/23 @9:00am

qsort::Ord a => [a] -> [a] 
qsort [] = []  -- for empty
qsort (x:xs) = 
  let hi = filter (>x) xs 
      lo = filter(<=x) xs
  in qsort lo ++ [x] ++ qsort hi 


mergeit::Ord a => [a] -> [a] -> [a]
mergeit [] back = back  -- if front empty return backside 
mergeit front [] = front     -- if back empty return frontside 
mergeit (front:fts) (back:bcs)  -- both nonempty 
  | (back <= front)  = back : mergeit bcs (front:fts) 
  | otherwise = front : mergeit (back:bcs) fts  -- front > back 

 
msort::Ord a => [a] -> [a]
msort [] = [] 
msort [x] = [x] -- containing one element
msort xs = 
  let front = take (length xs `div` 2) xs 
      back = drop (length xs `div` 2) xs 
  in mergeit (msort front) (msort back)

main = do
  -- Testing Quicksort
  print "Quicksort:"
  -- No elements 
  -- qsort [] -- Expected: [] -- pass 

  -- 1 element
  print(qsort([55])) -- Expected: [55]

  -- 2 elements
  print(qsort([2,1])) -- Expected: [1,2]

  -- Repeated element / Odd number elemets 
  print(qsort([3,24,52,5,12,4,24])) -- Expected: [3,4,5,12,24,24,52]

  -- Negative input 
  print(qsort([-3,-55,0,-88,7])) -- Expected: [-88,-55,-3,0,7]

  -- Reversed input 
  print(qsort([6,5,4,3,2,1])) -- Expected: [1,2,3,4,5,6]

  -- Char input, list of chars is a string
  print(qsort(['o','r','s','o','n'])) -- Expected: "noors"

  -- Decimal input, converts all to doubles - one decimal place
  print(qsort([3.5,3,65,12.3,1.2,5])) -- Expected: [1.2,3.0,3.5,5.0,12.3,65.0]

  -- Testing Mergesort
  print("- - - - - - - - -")
  print "Mergesort:"

  -- No elements 
  -- msort [] -- Expected [] -- pass 

  -- 1 element
  print(msort([55])) -- Expected: [55]

  -- 2 elements
  print(msort([2,1])) -- Expected: [1,2]

  -- Repeated element / Odd number elements 
  print(msort([3,24,52,5,12,4,24])) -- Expected: [3,4,5,12,24,24,52]
      --       3 4 5 12 24 24 52 

  print(msort([-3,-55,0,-88,7])) -- Expected: [-88,-55,-3,0,7]
  
  -- Reversed input 
  print(msort([6,5,4,3,2,1])) -- Expected: [1,2,3,4,5,6]

  -- Char input
  print(msort(['s','c','o','t','t'])) -- Expected: "costt"

  -- Decimal input
  print(msort([3.5,3,65,12.3,1.2,5])) -- Expected: [1.2,3.0,3.5,5.0,12.3,65.0]