// Problem 31
// In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// How many different ways can £2 be made using any number of coins?

package main

import (
	"fmt"
)

func enumerate_how_many(coins []int, limit int) int {
	n_coins := len(coins)
	total := 0
	var enumerate func(c, partial int)
	enumerate = func(c, partial int) {
		if c == n_coins {
			if (partial == limit) {
				total += 1
			}
		} else {
			for i := 0; i <= limit - partial; i += coins[c] {
				enumerate(c + 1, partial + i)
			}
		}
	}
	enumerate(0, 0)
	return total
}

func solve_how_many(coins []int, limit int) int {
	how_many := make([]int, limit + 1)
	how_many[0] = 1
	for _, c := range(coins) {
		for i := c; i <= limit; i++ {
			how_many[i] += how_many[i - c]
		}
	}
	return how_many[limit]
}

func main() {
	const limit = 200
	coins := []int{1,2,5,10,20,50,100,200}
	fmt.Println(solve_how_many(coins, limit))
}
