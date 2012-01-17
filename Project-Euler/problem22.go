// Problem 22

package main

import ("io/ioutil"; "fmt"; "strings"; "sort")

func value(name string) uint64 {
	var sum uint64 = 0
	for _, v := range(name) {
		sum += uint64(v - 'A' + 1)
	}
	return sum
}

func main() {
	const n_digits = 10
	contents, err := ioutil.ReadFile("names22.txt")
	if err != nil {
		fmt.Printf("Error opening file: %v", err)
		return
	}
  names := strings.FieldsFunc(string(contents), func(c int) bool {
		return c == '"' || c == ','
	})
	sort.Sort(sort.StringSlice(names))
	var score uint64 = 0
	for i, name := range(names) {
		score += uint64(i+1) * value(name)
	}
	fmt.Println(score)
}
