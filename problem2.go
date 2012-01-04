package main

import "fmt"

const num_receivers := 2

func fibonacci_producer(limit uint64, ch chan uint64) {
	var last, next uint64 = 1, 1
	for next <= limit {
		ch <- next
		last, next = next, last + next
	}
	close(ch)
}

func receiver(id int, ch chan uint64, output chan uint64) {
	var sum uint64 = 0
  for i := range ch {
		if i % 2 == 0 {
			sum += i
		}
  }
	output <- sum
}

func even_fibonacci_producer(limit uint64, ch chan uint64) {
	var last, next uint64 = 0, 2
	for next <= limit {
		ch <- next
		last, next = next, last + 4*next
	}
	close(ch)
}

func even_receiver(id int, ch chan uint64, output chan uint64) {
	var sum uint64 = 0
  for i := range ch {
		sum += i
  }
	output <- sum
}


func main() {
	var limit uint64 = 4000000
	ch := make(chan uint64)
	output := make(chan uint64)
	go even_fibonacci_producer(limit, ch)
	for i := 0; i < num_receivers; i++ {
		go even_receiver(i, ch, output)
	}
	var sum uint64 = 0
  for i := 0; i < num_receivers; i++ {
		sum += <- output
	}
	fmt.Printf("Sum = %d\n", sum)
}
