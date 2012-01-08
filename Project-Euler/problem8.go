// Problem 8
// Find the greatest product of five consecutive digits in the 1000-digit number.

package main

import ("fmt"; "strings"; "strconv")

const number = `
73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450
`

func conv_to_digits(str string) []int {
	tmp := strings.Replace(str, "\n", "", -1)
	digits := make([]int, len(tmp))
	for i := range(tmp) {
		digits[i], _ = strconv.Atoi(tmp[i:i+1])
	}
	return digits
}

// Solution in O(len(digits) * seq_size)
//func find_max_prod_slow(digits []int, seq_size int) (max_prod, pos int) {
//	max_prod = 0
//	for i := range(digits) {
//		prod := 1
//		for j := 0; j < seq_size; j++ {
//			if i + j >= len(digits) {
//				prod = 0
//				break
//			}
//			prod *= digits[i + j]
//		}
//		if prod > max_prod {
//			max_prod, pos = prod, i
//		}
//	}
//	return
//}

// Solution in O(len(digits))
func find_max_prod_linear(digits []int, seq_size int) (max_prod, pos int) {
	max_prod = 0
	prod, zeros := 1, 0
	for i, v := range(digits) {
		if i - seq_size >= 0 {
			if zeros == 0 {
				prod /= digits[i - seq_size]
			}
			if digits[i - seq_size] == 0 {
				zeros--
			}
		}

		if v > 0 {
			prod *= v
			if zeros == 0 && prod > max_prod {
				max_prod, pos = prod, i-seq_size+1
			}
		} else {
			zeros, prod = zeros + 1, 1
		}
	}
	return
}

func print_highlighted_max_prod(digits []int, pos, seq_size int) {
	prt := func(begin, end int) {
		for i := begin; i < end; i++ {
			fmt.Printf("%d", digits[i])
		}
	}
	prt(0, pos)
	fmt.Printf(" <<<")
	prt(pos, pos + seq_size)
	fmt.Printf(">>> ")
	prt(pos + seq_size, len(digits))
	fmt.Printf("\n")
}


func main() {
	const seq_size = 5
	digits := conv_to_digits(number)
	max_prod, pos := find_max_prod_linear(digits, seq_size)
	print_highlighted_max_prod(digits, pos, seq_size)
 	fmt.Printf("Max prod: %v = %d\n", digits[pos : pos + seq_size], max_prod)

//	max_prod, pos = find_max_prod_quadratic(digits, seq_size)
//	print_highlighted_max_prod(digits, pos, seq_size)
//	fmt.Printf("Max prod: %v = %d\n", digits[pos : pos + seq_size], max_prod)
}

