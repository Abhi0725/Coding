// Problem 21
// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000.

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


func main() {
	const first, last = 1, 10000
	const n_threads = 4
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
	sum := 0
	for i_a, b := range(sum_of_div) {
		a, i_b := i_a + first, b - first
		if a != b && i_b >= 0 && i_b < len(sum_of_div) &&  sum_of_div[i_b] == a {
			sum += a
		}
	}
	fmt.Printf("The sum of all amicable pairs within [%d, %d] is %d\n", first, last, sum)
}

