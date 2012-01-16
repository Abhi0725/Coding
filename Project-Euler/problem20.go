// Problem 20
// n! means n * (n  1) * ... * 3 * 2 * 1
// For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
// Find the sum of the digits in the number 100!

package main

import ("fmt"; "big")

func prod(n int) *big.Int {
	prod := big.NewInt(1)
	i, inc := big.NewInt(1), big.NewInt(1)
	for ; n > 0; n-- {
		prod.Mul(prod, i)
		i.Add(i, inc)
	}
	return prod
}

func main() {
	const n = 100
	number := prod(n)
	fmt.Printf("%d! = %d\n", n, number)
	str := number.String()
	var sum uint64 = 0
	for _, v := range(str) {
		sum += uint64(v - '0')
	}
	fmt.Printf("The sum of the digits of %d! is %d\n", n, sum)
}

