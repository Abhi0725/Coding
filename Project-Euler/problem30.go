// Problem 30
// Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
// 1634 = 14 + 64 + 34 + 44
// 8208 = 84 + 24 + 04 + 84
// 9474 = 94 + 44 + 74 + 44
// As 1 = 14 is not a sum it is not included.
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

package main

import (
	"fmt"
	"math"
)

func pre_compute_powers(power int) []uint64 {
	powers := make([]uint64, 10)
	for i := range(powers) {
		powers[i] = uint64(i)
		for j := 1; j < power; j++ {
			powers[i] *= uint64(i)
		}
	}
	return powers
}

func find_upper_bound(max_per_digit float64) int {
	for n_digits := 1;  ; n_digits++ {
		max_sum := float64(n_digits) * max_per_digit
		min_number := math.Pow10(n_digits - 1)
		if max_sum < min_number {
			return n_digits
		}
	}
	return -1  // never gets here
}

func find_numbers(power int) []uint64 {
	pow := pre_compute_powers(power)
	n_digits := find_upper_bound(float64(pow[9]))
	output := make([]uint64, 0, 1000)
	var rec_find_numbers func(sum, number uint64, d int)
	rec_find_numbers = func(sum, number uint64, d int) {
		if d != n_digits {
			start := 0
			if d == 0 { start = 1 }
			for digit := start; digit <= 9; digit++ {
				new_number := number*10 + uint64(digit)
				new_sum := sum + pow[digit]
				if d > 0 && new_number == new_sum {
					output = append(output, new_number)
				}
				rec_find_numbers(new_sum, new_number, d+1)
			}
		}
	}
	rec_find_numbers(0, 0, 0)

	return output
}

func main() {
	const power = 5
	numbers := find_numbers(power)
	var sum uint64 = 0
	for _, n := range(numbers) {
		sum += n
	}
	fmt.Printf("The sum of all the numbers that can be written as the sum of %dth power of their digits is %v.\n", power, sum)
	fmt.Printf("And the numbers are: %v.\n", numbers)
}