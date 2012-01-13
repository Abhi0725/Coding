// Problem 15
// Starting in the top left corner of a 2x2 grid, there are 6 routes (without backtracking) to the bottom right corner.
// How many routes are there through a 20x20 grid?

package main

import "fmt"

func alloc_int_matrix(d1, d2 int, init uint64) [][]uint64 {
	matrix := make([][]uint64, d1)
	for i := range(matrix) {
		matrix[i] = make([]uint64, d2)
		for j := range(matrix[i]) {
			matrix[i][j] = init
		}
	}
	return matrix
}

func compute_table(N, M int) [][]uint64 {
	N, M = N+1, M+1
	table := alloc_int_matrix(N, M, 1)
	for i := 1; i < N; i++ {
		for j := 1; j < M; j++ {
			table[i][j] = table[i-1][j] + table[i][j-1]
		}
	}
	return table
}

func main() {
	const N, M = 20, 20
	table := compute_table(N, M)
	fmt.Printf("For %dx%d grid, there are %d routes\n", N, M, table[N][M])
}
