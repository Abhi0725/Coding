// Problem 4
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.
// Find the largest palindrome made from the product of two 3-digit numbers.

package main

import "fmt"
import "math"

func make_is_product_func(n_digits int) func(num int) (bool, int, int) {
	min := int(math.Pow(10, float64(n_digits - 1)))
	max := 10*min
	return func(num int) (bool, int, int) {
		for i := min; i < max; i++ {
			if num % i == 0 && num / i >= min && num/i < max {
				return true, i, num/i
			}
		}
		return false, 0, 0
	}
}

func find_palindrome(n_digits int, test func(num int) bool) int {
	max := int(math.Pow(10, float64((n_digits + 1)/2)))
	mult := int(math.Pow(10, float64((n_digits)/2)))
	for i := max - 1; i >= max/10; i-- {
		tmp, low  := i, 0
		for j := 0; j < (n_digits + 1)/2; j++ {
			low = low * 10 + tmp % 10
			tmp /= 10
		}
		num := mult * i + low % mult
		if test(num) {
			return num
		}
	}
	return 0
}

func main() {
	const factors_num_digits = 3
	const palindrome_num_digits = 2 * factors_num_digits
	tester := make_is_product_func(factors_num_digits)
	num := find_palindrome(palindrome_num_digits, func(num int) bool {
		r, _, _ := tester(num)
		return r
	})
	found, p1, p2 := tester(num)
	if found {
		fmt.Printf("The largest palindrome made from the product of two %d-digit numbers is %d:\n", factors_num_digits, num)
		fmt.Printf(" %d x %d = %d\n", p1, p2, p1 * p2)
	} else {
		fmt.Printf("Did not found a palindrome :-(")
	}
}
