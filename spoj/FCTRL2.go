
package main

import (
	"fmt"
	"big"
)

func make_factorial(limit int) []*big.Int {
	factorial := make([]*big.Int, limit + 1)
	factorial[0] = big.NewInt(1)
	mult, one := big.NewInt(1), big.NewInt(1)
	for i := 1; i <= limit; i++ {
		factorial[i] = new(big.Int).Mul(mult, factorial[i-1])
		mult.Add(mult, one)
	}
	return factorial
}

func main() {
	const limit = 100
	factorial := make_factorial(limit)
	var t, n int
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanf("%d", &n)
		fmt.Println(factorial[n])
	}
}
