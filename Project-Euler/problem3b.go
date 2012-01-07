// Problem 3
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

package main

import "fmt"
import "math"

func largest_prime_factor(value uint64) (largest uint64) {
	limit := uint64(math.Sqrt(float64(value)))
	var i uint64
	for i = 2; i <= limit; i++ {
		if value % i == 0 {
			largest = i
			for value /= i; value % i == 0; value /= i { }
		}
	}
	if value > largest {
		largest = value
	}
	return largest
}

func main() {
	const value = 600851475143
	largest := largest_prime_factor(value)
	fmt.Printf("largest prime factor of %v is %v\n", uint64(value), largest)
}
