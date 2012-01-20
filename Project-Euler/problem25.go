// Problem 25
// What is the first term in the Fibonacci sequence to contain 1000 digits?

package main

import (
	"fmt";
	"big";
)

func make_fibonacci() func() *big.Int {
	last, next := big.NewInt(1), big.NewInt(1)
	return func () *big.Int {
		tmp := new(big.Int).Set(last)
		last.Set(next)
		next.Add(tmp, next)
		return tmp
	}
}

func main() {
	const limit = 1000
	fibonacci := make_fibonacci()
	var last_fib *big.Int
	var last_idx int
	for i := 1; ; i++ {
		last_fib = fibonacci()
		if len(last_fib.String()) >= limit {
			last_idx = i
			break
		}
	}
	fmt.Printf("Fib(%d) = %v, is the first term in the Fibonacci sequence >= %v\n", last_idx, last_fib, limit)
}
