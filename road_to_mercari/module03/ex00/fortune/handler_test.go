package fortune_test

import (
	"io/ioutil"
	"net/http"
	"net/http/httptest"
	"testing"

	"example.com/ex00/fortune"
)

var expects = []string{
	"{\"fortune\":\"Dai-kichi\"}\n",
	"{\"fortune\":\"Kichi\"}\n",
	"{\"fortune\":\"Chuu-kichi\"}\n",
	"{\"fortune\":\"Sho-kichi\"}\n",
	"{\"fortune\":\"Sue-kichi\"}\n",
	"{\"fortune\":\"Kyo\"}\n",
	"{\"fortune\":\"Dai-kyo\"}\n",
}

func TestDraw(t *testing.T) {
	w := httptest.NewRecorder()
	r := httptest.NewRequest("GET", "/", nil)
	fortune.Draw(w, r)
	rw := w.Result()
	defer rw.Body.Close()
	if rw.StatusCode != http.StatusOK {
		t.Fatal("unexpected status code")
	}
	b, err := ioutil.ReadAll(rw.Body)
	if err != nil {
		t.Fatal("unexpected error")
	}
	if s := string(b); !isSinStringArray(s, expects) {
		t.Fatalf("error: got: [%s]", s)
	}
}

func isSinStringArray(s string, strs []string) bool {
	for _, e := range strs {
		if e == s {
			return true
		}
	}
	return false
}
