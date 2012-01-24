// Problem 34

package main

import (
	"fmt"
	"math"
)

func pre_compute_factorial() []uint64 {
	factorial := make([]uint64, 10)
	factorial[0] = uint64(1)
	for n := 1; n < len(factorial); n++ {
		factorial[n] = uint64(n) * factorial[n-1]
	}
	return factorial
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

func find_numbers() []uint64 {
	factorial := pre_compute_factorial()
	n_digits := find_upper_bound(float64(factorial[9]))
	output := make([]uint64, 0, 1000)
	var rec_find_numbers func(sum, number uint64, d int)
	rec_find_numbers = func(sum, number uint64, d int) {
		if d != n_digits {
			start := 0
			if d == 0 { start = 1 }
			for digit := start; digit <= 9; digit++ {
				new_number := number*10 + uint64(digit)
				new_sum := sum + factorial[digit]
				if d > 0 && new_number == new_sum {
					output = output[0:len(output)+1]
					output[len(output)-1] = new_number
				}
				rec_find_numbers(new_sum, new_number, d+1)
			}
		}
	}
	rec_find_numbers(0, 0, 0)

	return output
}

func main() {
	numbers := find_numbers()
	var sum uint64 = 0
	for _, n := range(numbers) {
		sum += n
	}
	fmt.Printf("The sum of all the numbers which are equal to the sum of the factorial of their digits is %v.\n", sum)
	fmt.Printf("And the numbers are: %v.\n", numbers)
}