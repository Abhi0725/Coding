// Problem 28
// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
// It can be verified that the sum of the numbers on the diagonals is 101.
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

package main

import "fmt"

type Direction struct {
	X int64
	Y int64
}

var directions = []Direction {
	{ 0, -1},
	{ 1,  0},
	{ 0,  1},
	{-1,  0},
}

func make_spiral(n int64) ([][]int64, int64) {
	spiral := make([][]int64, n)
	for i := range(spiral) {
		spiral[i] = make([]int64, n)
	}
	var counter int64 = n * n
	var sum int64 = 0
	d, i, j := 0, int64(0), n-1
	for {
		spiral[i][j] = counter

		if i == j || i + j + 1 == n {
			sum += counter
		}

		i, j = i + directions[d].X, j + directions[d].Y
		if i < 0 || i >= n || j < 0 || j >= n || spiral[i][j] != 0 {
			i, j = i - directions[d].X, j - directions[d].Y
			d = (d + 1) % 4
			i, j = i + directions[d].X, j + directions[d].Y
			if spiral[i][j] != 0 {
				break
			}
		}
		counter--
	}
	return spiral, sum
}

func print_spiral(spiral [][]int64) {
	for i := range(spiral) {
		for j := range(spiral[i]) {
			fmt.Printf(" %3d", spiral[i][j])
		}
		fmt.Println()
	}
}

func main() {
	const limit = 1001
//	spiral, sum := make_spiral(limit)
//	print_spiral(spiral)
	_, sum := make_spiral(limit)
	fmt.Println(sum)
}