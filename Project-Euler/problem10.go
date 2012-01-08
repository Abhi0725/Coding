// Problem 10
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

package main

import "fmt"

func make_crivo(limit int) []bool {
	crivo := make([]bool, limit + 1)
	for i := range(crivo) {
		crivo[i] = true
	}
	crivo[0], crivo[1] = false, false
	for i, v := range(crivo) {
		if v {
			for j := 2 * i; j <= limit; j += i {
				crivo[j] = false
			}
		}
	}
	return crivo
}

func main() {
//	const limit = 10
	const limit = 2000000
	crivo := make_crivo(limit - 1)
	var sum uint64 = 0
	for i, v := range(crivo) {
		if v {
			sum += uint64(i)
		}
	}
	fmt.Printf("The sum of the primes below %d is %d\n", limit, sum)
}