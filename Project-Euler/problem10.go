// Problem 10
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

package main

import "fmt"

func make_sieve(limit int) []bool {
	sieve := make([]bool, limit + 1)
	for i := range(sieve) {
		sieve[i] = true
	}
	sieve[0], sieve[1] = false, false
	for i, v := range(sieve) {
		if v {
			for j := 2 * i; j <= limit; j += i {
				sieve[j] = false
			}
		}
	}
	return sieve
}

func main() {
//	const limit = 10
	const limit = 2000000
	sieve := make_sieve(limit - 1)
	var sum uint64 = 0
	for i, v := range(sieve) {
		if v {
			sum += uint64(i)
		}
	}
	fmt.Printf("The sum of the primes below %d is %d\n", limit, sum)
}