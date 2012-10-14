// Problem 35
// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// How many circular primes are there below one million?


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

func next(n, m int) int {
	n *= 10
	return n%m + n/m
}

func how_many_circular_primes(sieve []bool, limit int) int {
	circle_length := func(n, m int) int {
		count, start := 1, n
		for n = next(n, m); n != start; n = next(n, m) {
			if n < start || !sieve[n] {
				return 0
			}
			count++
		}
		return count
	}
	total, m := 0, 1
	for i, is_prime := range(sieve) {
		if is_prime {
			for ; m < i; m *= 10 { }  // update m
			total += circle_length(i, m)
		}
	}
	return total
}

func main() {
	const limit = 1000000
	sieve := make_sieve(limit)
	total := how_many_circular_primes(sieve, limit)
	fmt.Printf("There are %d circular primes below %d.\n", total, limit)
}