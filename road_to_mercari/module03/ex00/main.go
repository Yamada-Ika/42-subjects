package main

import (
	"fmt"
	"os"

	"example.com/ex00/fortune"
)

func main() {
	portNum, err := fortune.ParsePortNum(os.Args[1:])
	if err != nil {
		fmt.Fprintf(os.Stderr, err.Error())
		os.Exit(1)
	}
	fortune.Handle("/", fortune.Draw)
	if err := fortune.Listen(portNum); err != nil {
		fmt.Fprintf(os.Stderr, err.Error())
		os.Exit(1)
	}
}
