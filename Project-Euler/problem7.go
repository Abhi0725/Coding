// Problem 7
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?

package main

import "fmt"
import "math"

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

func print_sieve(sieve []bool) {
	for i, v := range(sieve) {
//		fmt.Printf("%3d: %v\n", i, v)
		if v {
			fmt.Printf("\t%4d", i)
		}
	}
	fmt.Printf("\n")	
}

func found_ith_prime(sieve []bool, i int) (int, bool) {
	count := 0
	for j, v := range(sieve) {
		if v {
			count++
			if count == i {
				return j, true
			}
		}
	}
	return count, false
}

func main() {
	const target = 10001
	limit := int(1.5 * target * math.Log(target))
	sieve := make_sieve(limit)
	value, found := found_ith_prime(sieve, target)
	if found {
		fmt.Printf("The %dth prime number is %d\n", target, value)
	} else {
		fmt.Printf("Found only %d primes within the first %d numbers, please change the limit.\n", value, limit)
	}
}
