// Problem 13
// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

package main

import ("io/ioutil"; "fmt"; "strconv"; "math"; "strings")

func conv_to_digits(numbers []string) [][]int {
	output := make([][]int, len(numbers))
	for i := range(numbers) {
		output[i] = make([]int, len(numbers[i]))
		for j := range(numbers[i]) {
			output[i][j], _ = strconv.Atoi(numbers[i][j:j+1])
		}
	}
	return output
}

func conv_to_string(number []int) string {
	str := ""
	for _, v := range(number) {
		str += strconv.Itoa(v)
	}
	return str
}

func reverse(v []int) []int {
	for i, j := 0, len(v)-1; i < j; i, j = i+1, j-1 {
    v[i], v[j] = v[j], v[i]
	}
	return v
}

// all numbers must have the same number of digits
func adder(numbers [][]int) []int {
	n := len(numbers[0])
	max_new_digits := int(math.Ceil(math.Log10(float64(len(numbers)))))
	result := make([]int, n, n + max_new_digits)
	carry := 0
	for i, j := 0, n-1; i < n; i, j = i+1, j-1 {
		result[i] = carry
		for k := range(numbers) {
			result[i] += numbers[k][j]
		}
		carry = result[i] / 10
		result[i] = result[i] % 10
	}
	for i := n; carry > 0; i++ {
		result = result[0:len(result) + 1]
		result[i], carry = carry % 10, carry/10
	}
	return reverse(result)
}

func count_ndigits(x uint64) int {
	var n int
	for n = 0; x > 0; n++ {
		x /= 10
	}
	return n
}

func main() {
	const n_digits = 10
	contents, err := ioutil.ReadFile("input13.txt")
	if err != nil {
		fmt.Printf("Error opening file: %v", err)
		return
	}
  numbers := strings.Fields(string(contents))
	converted := conv_to_digits(numbers)
	str := conv_to_string(adder(converted))
	fmt.Println(str[0:n_digits])
}