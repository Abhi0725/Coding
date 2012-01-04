package main

import "fmt"

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
  num_threads := 2
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