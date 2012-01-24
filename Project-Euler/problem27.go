// Problem 27
// Considering quadratics of the form:
// n^2 + an + b, where |a|  1000 and |b|  1000
// Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

package main

import "fmt"

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

func try_all_quadratics(crivo []bool, limit int) (int, int, int) {
	n, max, max_a, max_b := 0, -1, 0, 0
	for a := -limit; a <= limit; a++ {
		for b := -limit; b <= limit; b++ {
			if a + b <= 1 {
				continue
			}
			for n = 0;  ; n++ {
				v := n * n + a * n + b
				if v < 2 || !crivo[v] {
					break
				}
			}
			if n > max {
				max, max_a, max_b = n, a, b
			}
		}
	}
	return max, max_a, max_b
}


func main() {
	const limit = 1000
	const crivo_limit = 101010
	crivo := make_crivo(crivo_limit)
	max, max_a, max_b := try_all_quadratics(crivo, limit - 1)
	fmt.Printf("n^2 + (%d)*n + (%d) produces %d consecutive primes for n >= 0.\n", max_a, max_b, max)
	fmt.Printf("a * b = %v\n", max_a * max_b)
}
