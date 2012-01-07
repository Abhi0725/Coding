//Problem 6
//The sum of the squares of the first ten natural numbers is,
//  12 + 22 + ... + 102 = 385
//The square of the sum of the first ten natural numbers is,
//  (1 + 2 + ... + 10)2 = 552 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

package main

import "fmt"

func loop_solution(limit uint64) uint64 {
	var sum, sum_of_squares uint64 = 0, 0
	var i uint64
	for i = 1; i <= limit; i++ {
		sum += i
		sum_of_squares += i*i
	}
	return sum * sum - sum_of_squares
}

func direct_solution(limit uint64) uint64 {
	sum := (limit + 1) * limit / 2
	sum_of_squares := limit * (limit + 1) * (2*limit + 1)/6
	return sum * sum - sum_of_squares
}

func main() {
	const limit = 100
	fmt.Println(direct_solution(limit))
}