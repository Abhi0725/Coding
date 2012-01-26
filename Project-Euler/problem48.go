// Problem 48
// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

package main

import ("fmt"; "big")

func main() {
	const limit = 1000
	const n_digits = 10
	sum := big.NewInt(0)
	for i := 1; i <= limit; i++ {
		n := big.NewInt(int64(i))
		n.Exp(n, n, nil)
		sum.Add(sum, n)
	}
	str := sum.String()
	fmt.Println(str[len(str) - n_digits:])
}
