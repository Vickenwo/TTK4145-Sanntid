// Use `go run foo.go` to run your program

package main

import (
	"fmt"
	"runtime"
)

func number_server(add <-chan int, sub <-chan int, read chan<- int) {
	var number = 0

	// This for-select pattern is one you will become familiar with...
	for {
		select {
		case <-add:
			number++
		case <- sub:
			number--
		case read <- number:
		}

	}
}

func incrementer(add chan<- int, finished chan<- bool) {
	for j := 0; j < 1000000; j++ {
		add <- 1
	}
	//TODO: signal that the goroutine is finished
	finished <- true
}

func decrementer(sub chan<- int, finished chan<- bool) {
	for j := 0; j < 1000000; j++ {
		sub <- 1
	}
	//TODO: signal that the goroutine is finished
	finished <- true
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())

	// TODO: Construct the remaining channels
	read := make(chan int)
	add := make(chan int)
	sub := make(chan int)
	finished := make(chan bool, 2)

	// TODO: Spawn the required goroutines
	go incrementer(add, finished)
	go decrementer(sub, finished)
	go number_server(add, sub, read)


	// TODO: block on finished from both "worker" goroutines
	for j:= 0; j < 2; j++{
			<-finished
	}


	fmt.Println("The magic number is:", <-read)
}
