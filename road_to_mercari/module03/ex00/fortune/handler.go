package fortune

import (
	"bytes"
	"encoding/json"
	"fmt"
	"net/http"
)

func Draw(w http.ResponseWriter, r *http.Request) {
	var buf bytes.Buffer

	d := &DefaultDater{}
	result := drawOmikuji(d)
	enc := json.NewEncoder(&buf)
	if err := enc.Encode(&result); err != nil {
		return
	}

	fmt.Fprint(w, buf.String())
	// _, err := fmt.Fprint(w, buf.String())
	// if err != nil {
	// 	return
	// }
}
