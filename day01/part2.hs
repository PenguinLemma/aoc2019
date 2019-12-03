getFuel :: Integer -> Integer
getFuel mass
    | mass < 9  = 0
    | otherwise = fuel + (getFuel fuel) where fuel = mass `div` 3 - 2

readInt :: String -> Integer
readInt a = read a ::Integer

main :: IO ()
main = do
    full_file_as_string <- readFile "input.txt"
    let module_masses = map readInt (lines (full_file_as_string))
    print (sum (map getFuel module_masses))