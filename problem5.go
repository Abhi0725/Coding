// Problem 5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

package main

import "fmt"

func solve(limit int) int {
	numbers := make([]int, limit)
	for i := range(numbers) {
		numbers[i] = i + 1
	}
	solution := 1
	for i, v := range(numbers) {
		if v > 1 {
			max_fact := 0
			for j := i; j < limit; j += v {
				m := v
				for numbers[j] /= v; numbers[j] % v == 0; numbers[j] /= v {
					m *= v
				}
				if m > max_fact {
					max_fact = m
				}
			}
			solution *= max_fact
		}
	}
	return solution
}

func main() {
	const limit = 20
	fmt.Println(solve(limit))
}