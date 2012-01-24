// Problem 26
// Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

package main

import "fmt"

func fraction_cycle_length(n int) int {
	seen := make(map[int]map[int]int)
	for i := 0; i < 10; i++ { seen[i] = make(map[int]int) }
	pos := 0
	dividend := 1
	for dividend != 0 {
		pos += 1
		if dividend < n {
			dividend *= 10
		} else {
			digit := dividend / n
			if seen[digit][dividend] > 0 {
				return pos - seen[digit][dividend]
			}
			seen[digit][dividend] = pos
			dividend = 10 * (dividend % n)
		}
	}
	return 0  // never gets here
}

func main() {
	const limit = 1000
	max, max_i := 0, 0
	for i := 2; i < limit; i++ {
		length := fraction_cycle_length(i)
		if length > max {
			max, max_i = length, i
		}
	}
	fmt.Printf("For d<%v, the fraction 1/d = 1/%v has the longest recurring cycle (length %v).\n", limit, max, max_i)
}
