// Problem 13
// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

package main

import ("os"; "fmt"; "big")

func main() {
	const n_digits = 10
	sum := big.NewInt(0)

	f, err := os.Open("input13.txt")
	if err != nil {
		fmt.Printf("Error opening file: %v", err)
		return
	}
	defer f.Close()

	for {
		number := new(big.Int)
		_, err := fmt.Fscan(f, number)
		if err != nil{
			break
		}
		sum.Add(sum, number)
	}
	str := sum.String()
	fmt.Println(str[0:n_digits])
}