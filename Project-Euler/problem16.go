// Problem 16
// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?

package main

import ("fmt"; "big"; "math")

// Requires: base > 0, exp > 0
func pow(base, exp int64) *big.Int {
	powers := make([]*big.Int, 1 + int(math.Ceil(math.Log2(float64(exp)))))
	powers[0] = big.NewInt(base)
	for i := 1; i < len(powers); i++ {
		powers[i] = new(big.Int).Mul(powers[i-1], powers[i-1])
	}
	result := big.NewInt(1)
	for p := 0; exp > 0; p++ {
		if exp % 2 != 0 {
			result.Mul(result, powers[p])
		}
		exp /= 2
	}
	return result
}

func main() {
	const base, exp = 2, 1000
	number := pow(base, exp)
	str := number.String()
	var sum uint64 = 0
	for _, v := range(str) {
		sum += uint64(v - '0')
	}
	fmt.Printf("The sum of the digits of the number %d^%d is %d\n", base, exp, sum)
}
