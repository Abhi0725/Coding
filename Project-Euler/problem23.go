// Problem 23
// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

package main

import "fmt"

type SumOfDivisors []int

func (sum SumOfDivisors) sum_of_divisors(first, last, offset int, ch chan int) {
	limit := last/2
	for i := 1; i <= limit; i++ {
		for j := first; j < last; j++ {
			if j > i && j % i == 0 {
				sum[j - offset] += i
			}
		}
	}
	fmt.Printf("Done [%d, %d)\n", first, last)
	ch <- 1
}

func compute_sum_of_divisors(first, last, n_threads int) SumOfDivisors {
	ch := make(chan int)
	sum_of_div := make(SumOfDivisors, last-first+1)
	for i := 0; i < n_threads; i++ {
		f := first + i * (last-first+1)/n_threads
		e := first + (i+1) * (last-first+1)/n_threads
		go sum_of_div.sum_of_divisors(f, e, first, ch)
	}
	for i := 0; i < n_threads; i++ {
		<- ch
	}
	return sum_of_div
}

func abundant(n int, sum_of_div SumOfDivisors) []bool {
	abundant := make([]bool, n)
	for i := 0; i < n; i++ {
		abundant[i] = (sum_of_div[i] > i)
	}
	return abundant
}

func are_sum_of_two_abundants(n int, abundants []bool) []bool {
	is_sum := make([]bool, n)
	for i := range(is_sum) {
		is_sum[i] = false
	}
	for i := range(is_sum) {
		if abundants[i] {
			for j := 0; i + j < len(is_sum); j++ {
				if abundants[j] {
					is_sum[i + j] = true
				}
			}
		}
	}
	return is_sum
}


func main() {
	const first, last = 0, 28200
	const n_threads = 4
	sum_of_div := compute_sum_of_divisors(first, last, n_threads)
//	fmt.Println(sum_of_div)
	abundants := abundant(last + 1, sum_of_div)
	is_sum := are_sum_of_two_abundants(last + 1, abundants)
	var sum uint64 = 0
	for i, v := range(is_sum) {
		if !v {
//			fmt.Printf("%d is sum of abundants\n", i)
			sum += uint64(i)
		}
	}
	fmt.Printf("The sum of all the positive integers which cannot be written as the sum of two abundant numbers is %d.\n", sum)
}

