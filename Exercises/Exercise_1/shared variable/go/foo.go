// Use `go run foo.go` to run your program

package main

import (
    . "fmt"
    "runtime"
    "time"
)

var i = 0

func incrementing() {
	for b := 0; b < 1000000; b++ {
		i ++
        if b%100000 == 0 {
        Println("The magic number is:", i)
    }
	}
}

func decrementing() {
	for c := 0; c < 1000000; c++ {
		i --
        if c%100000 == 0 {
        Println("The magic number is:", i)
    }
	}
}

func main() {
    // What does GOMAXPROCS do? What happens if you set it to 1?
    runtime.GOMAXPROCS(2)    
	go incrementing()
    go decrementing()
    // TODO: Spawn both functions as goroutines
	
    // We have no direct way to wait for the completion of a goroutine (without additional synchronization of some sort)
    // We will do it properly with channels soon. For now: Sleep.
    time.Sleep(500*time.Millisecond)
    Println("The final magic number is:", i)
}
