// Problem 3
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

package main

import "fmt"
import "math"

func make_crivo(limit int) []bool {
	crivo := make([]bool, limit + 1)
	for i := range(crivo) {
		crivo[i] = true
	}
	crivo[0], crivo[1] = false, false
	for i, v := range(crivo) {
		if v {
			for j := 2 * i; j <= limit; j += i {
				crivo[j] = false
			}
		}
	}
	return crivo
}

func print_crivo(crivo []bool) {
	for i, v := range(crivo) {
//		fmt.Printf("%3d: %v\n", i, v)
		if v {
			fmt.Printf("\t%4d", i)
		}
	}
	fmt.Printf("\n")	
}

func prime_factors(value uint64) ([]int, []int) {
	factors, pow := []int{}, []int{}
	crivo := make_crivo(int(math.Sqrt(float64(value))))
//	print_crivo(crivo)
	for i, v := range(crivo) {
		if v && value % uint64(i) == 0 {
			factors = append(factors, i)
			p := 1
			for value /= uint64(i); value % uint64(i) == 0; value /= uint64(i) {
				p += 1
			}
			pow = append(pow, p)
		}
	}
	if value > 1 {
		factors = append(factors, int(value))
		pow = append(pow, 1)
	}
	return factors, pow
}

func main() {
	const value = 600851475143
	factors, pow := prime_factors(value)
	for i := range(factors) {
		fmt.Printf("%6d^%d is a divisor of %v\n", factors[i], pow[i], uint64(value))
	}

	fmt.Printf("%v = ", uint64(value))
	for i := range(factors) {
		if i > 0 {
			fmt.Printf(" *")
		}
		fmt.Printf(" %d^%d", factors[i], pow[i])
	}
	fmt.Printf("\n")

  var value_checker uint64 = 1
	for i := range(factors) {
		for j := 0; j < pow[i]; j++ {
			value_checker *= uint64(factors[i])
		}
	}
	if value_checker == uint64(value) {
		fmt.Println("Result checked, it's Okay! :-)")
	} else {
		fmt.Printf("Ooops, something is wrong. Computed = %v, expected = %v\n", value_checker, uint64(value))
	}
}
