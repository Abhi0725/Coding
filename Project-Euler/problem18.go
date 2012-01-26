// Problem 18
// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// That is, 3 + 7 + 4 + 9 = 23.
// Find the maximum total from top to bottom of the triangle below:
// [input18.txt]

package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"log"
	"strings"
)

func read_input(filename string) [][]int64 {
	triangle := make([][]int64, 0, 500)
	file, err := os.Open(filename)
	if err != nil {
    log.Fatalln(err)
  }
	defer file.Close()
	bfile := bufio.NewReader(file)
	line, err := bfile.ReadString('\n')
	for i := 0; err != os.EOF; i++ {
		triangle = append(triangle, make([]int64, i+1))
		fields := strings.Fields(line)
		if len(fields) != i + 1 {
			log.Fatalln(fmt.Sprintf("Found %d fields on line %d. Expected %d.", len(fields), i+1, i+1))
		}
		for j, f := range fields {
			triangle[i][j], _ = strconv.Atoi64(f)
		}
		line, err = bfile.ReadString('\n')
	}
	return triangle
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func maximum_total(triangle [][]int64) int64 {
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := range(triangle[i]) {
			best := max(triangle[i+1][j], triangle[i+1][j+1])
			triangle[i][j] += best
		}
	}
	return triangle[0][0]
}

func main() {
	triangle := read_input("input18.txt")
	for i := range(triangle) {
		for j := range(triangle[i]) {
			fmt.Printf(" %2d", triangle[i][j])
		}
		fmt.Printf("\n")
	}
	fmt.Printf("The maximum total from top to bottom in this triangle is %d.\n",
		maximum_total(triangle))
}
