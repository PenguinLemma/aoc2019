getFuel :: Integer -> Integer
getFuel mass
    | mass < 6  = 0
    | otherwise = mass `div` 3 - 2

readInt :: String -> Integer
readInt a = read a ::Integer

main :: IO ()
main = do
    full_file_as_string <- readFile "input.txt"
    let module_masses = map readInt (lines (full_file_as_string))
    print (sum (map getFuel module_masses))