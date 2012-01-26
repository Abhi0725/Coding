// Problem 81

package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"log"
	"strings"
	"unicode"
)

func read_input(filename string) [][]int64 {
	matrix := make([][]int64, 0, 500)
	file, err := os.Open(filename)
	if err != nil {
    log.Fatalln(err)
  }
	defer file.Close()
	bfile := bufio.NewReader(file)
	line, err := bfile.ReadString('\n')
	for i := 0; err != os.EOF; i++ {
		matrix = append(matrix, make([]int64, 0))
		fields := strings.FieldsFunc(line, func(c int) bool {
			return c == ',' || unicode.IsSpace(c)
		})
		if i > 0 && len(fields) != len(matrix[0]) {
			log.Fatalln(fmt.Sprintf("Found %d fields on line %d. Expected %d.", len(fields), i+1, len(matrix[0])))
		}
		for _, f := range fields {
			value, _ := strconv.Atoi64(f)
			matrix[i] = append(matrix[i], value)
		}
		line, err = bfile.ReadString('\n')
	}
	return matrix
}

func min(a, b int64) int64 {
	if a > b {
		return b
	}
	return a
}

func minimal_path(matrix [][]int64) [][]int64 {
	h, w := len(matrix), len(matrix[0])
	for i := h - 2; i >= 0; i-- {
		matrix[i][w-1] += matrix[i+1][w-1]
	}
	for j := w - 2; j >= 0; j-- {
		matrix[h-1][j] += matrix[h-1][j+1]
	}
	for i := h - 2; i >= 0; i-- {
		for j := w - 2; j >= 0; j-- {
			best := min(matrix[i+1][j], matrix[i][j+1])
			matrix[i][j] += best
		}
	}
	return matrix
}

func main() {
	matrix := read_input("matrix81.txt")
	fmt.Println("Matrix:")
	for i := range(matrix) {
		for j := range(matrix[i]) {
			fmt.Printf(" %4d", matrix[i][j])
		}
		fmt.Printf("\n")
	}
	matrix = minimal_path(matrix)
	fmt.Println("Minimal distance matrix:")
	for i := range(matrix) {
		for j := range(matrix[i]) {
			fmt.Printf(" %4d", matrix[i][j])
		}
		fmt.Printf("\n")
	}
	fmt.Printf("The minimum path sun is %d.\n", matrix[0][0])
}
