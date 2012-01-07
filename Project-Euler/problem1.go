// Problem 1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
package main

import "fmt"

const num_threads = 2

func sum(inf, sup uint64, c chan uint64) {
  var sum uint64 = 0
	for i := inf; i < sup; i++ {
    if i % 3 == 0 || i % 5 == 0 {
      sum += i
    }
	}
  c <- sum
}

func multi_thread_solver(limit uint64) (total uint64) {
  c := make(chan uint64)
  for i := 0; i < num_threads; i++ {
    inf := 1 +   uint64(i) * (limit - 1)/uint64(num_threads)
    sup := 1 + uint64(i+1) * (limit - 1)/uint64(num_threads)
    go sum(inf, sup, c)
  }
  for i := 0; i < num_threads; i++ {
    total += <-c
  }
  return
}

func main() {
//	fmt.Println(multi_thread_solver(10))
	fmt.Println(multi_thread_solver(1000))
}