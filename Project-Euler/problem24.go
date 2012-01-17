// Problem 24
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

package main

import "fmt"

func fatorial(n int) uint64 {
	if n <= 0 {
		return 1
	}
	return uint64(n) * fatorial(n - 1)
}

func nth_permutation(n uint64) []int {
	used := make([]bool, 10)
	perm := make([]int, 10)
	var digit int
	for position := 0; position < 10; position++ {
		factor := fatorial(10 - position - 1)
		target := n / factor
		for digit = 0; target > 0 || used[digit]; digit++ {
			if !used[digit] {
				target--
			}
		}
		perm[position] = digit
		used[digit] = true
		n = n % factor
	}
	return perm
}

func main() {
	const target = 1000000
	perm := nth_permutation(target - 1)
	for _, v := range(perm) {
		fmt.Printf("%d", v)
	}
	fmt.Printf("\n")
}