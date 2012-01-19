package main

import (
	"fmt"
	"big"
)

func main() {
	const limit = 10
	var buffer string
	total, diff := new(big.Int), new(big.Int)
	klaudia, natalia := new(big.Int), new(big.Int)
	two := big.NewInt(2)
	for t := 0; t < limit; t++ {
		// This works in my computer, but not on spoj:
		// fmt.Scanf("%d %d", total, diff)
		fmt.Scanf("%s", &buffer)
		total.SetString(buffer, 10)
		fmt.Scanf("%s", &buffer)
		diff.SetString(buffer, 10)
		klaudia.Add(total, diff)
		klaudia.Div(klaudia, two)
		natalia.Sub(total, klaudia)
		fmt.Println(klaudia)
		fmt.Println(natalia)
	}
}
