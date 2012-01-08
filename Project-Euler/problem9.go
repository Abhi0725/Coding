// Problem 9
// A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
// a2 + b2 = c2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

package main

import "fmt"

func main() {
	const sum = 1000
	for a := 1; a < sum; a++ {
		for b := a; b + a < sum; b++ {
			c := sum - a - b
			if a * a + b * b == c * c {
				fmt.Printf("a, b, c = %d, %d, %d\n", a, b, c)
				fmt.Printf("a^2 + b^2 = %d^2 + %d^2 = %d + %d = %d = %d^2 = c^2\n", a, b, a*a, b*b, c*c, c)
				fmt.Printf("a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c)
				fmt.Printf("--> a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c)
			}
		}
	}
}