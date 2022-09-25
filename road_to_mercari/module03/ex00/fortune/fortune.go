package fortune

import (
	"errors"
	"net/http"
	"strconv"
)

func ParsePortNum(args []string) (string, error) {
	if len(args) != 1 {
		return "", errors.New("error: Invalid argument")
	}
	num, err := strconv.Atoi(args[0])
	if err != nil {
		return "", err
	}
	if num < 0 {
		return "", errors.New("error: Invalid port number")
	}
	return ":" + strconv.Itoa(num), nil
}

func Handle(endPoint string, handler func(http.ResponseWriter, *http.Request)) {
	http.HandleFunc("/", handler)
}

func Listen(portNum string) error {
	return http.ListenAndServe(portNum, nil)
}
