// Problem 14
// The following iterative sequence is defined for the set of positive integers:
// n -> n/2 (n is even)
// n -> 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
// Which starting number, under one million, produces the longest chain?
// NOTE: Once the chain starts the terms are allowed to go above one million.

package main

import "fmt"

func make_collatz(limit uint64) func(uint64) int {
	mem := make([]int, limit)
	var collatz func (n uint64) int
	collatz = func (n uint64) int {
		switch {
		case n <= 0:
			fmt.Println("Erro!")
			return -1
		case n < limit && mem[n] != 0:
			return mem[n]
		case n == 1:
			return 1
		case n % 2 == 0:
			result := 1 + collatz(n/2)
			if n < limit {
				mem[n] = result
			}
			return result
		case n % 2 == 1:
			result := 1 + collatz(3*n + 1)
			if n < limit {
				mem[n] = result
			}
			return result
		}
		return -1
	}
	return collatz
}




func main() {
	const limit = 1000000
	collatz := make_collatz(limit)
	max, max_i := 0, 0
	for i := 1; i < limit; i++ {
//		fmt.Printf("%3d -> %4d\n", i, collatz(uint64(i)))
		if collatz(uint64(i)) > max {
			max, max_i = collatz(uint64(i)), i
		}
	}
	fmt.Printf("The Collatz sequence starting with %d, with lenght %d, is the longest starting under %d\n", max_i, max, limit)
}
