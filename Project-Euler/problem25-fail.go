// Problem 25
// What is the first term in the Fibonacci sequence to contain 1000 digits?

// Note: I like this solution, but it doesn't work for the problem limits because
// numbers with 1000 digits doesn't fit in float64.

package main

import (
	"fmt";
	"sort";
	"math"
)

func make_fibonacci() func(n int) float64 {
	phi := (1 + math.Sqrt(5)) / 2
	psi := (1 - math.Sqrt(5)) / 2
	sqrt5 := math.Sqrt(5)
	return func (n int) float64 {
		nn := float64(n)
		return math.Floor((math.Pow(phi, nn) - math.Pow(psi, nn)) / sqrt5 + 0.5)
	}
}

func infinite_binary_search(sequence func(int) float64, validate func(float64) bool) int {
	start, end := 1, 2
	for {
		fmt.Printf("forward_search(%d,%d)\n", start, end)
		if validate(sequence(end)) {
			break
		}
		start, end = end, 2*end
	}
	fmt.Printf("bin_search(%d,%d)\n", start, end)
	answer := sort.Search(end - start, func(i int) bool {
		return validate(sequence(start + i))
	})
	return answer + start
}

func main() {
//	limit := math.Pow10(3 - 1)
	limit := math.Pow10(1000 - 1)
	fibonacci := make_fibonacci()
	n := infinite_binary_search(fibonacci, func(f float64) bool {
		return f >= limit
	})
	fmt.Printf("Fib(%d) = %v, is the first term in the Fibonacci sequence >= %v\n", n, fibonacci(n), limit)
}