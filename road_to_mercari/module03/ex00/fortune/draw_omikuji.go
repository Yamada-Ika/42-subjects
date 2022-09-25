package fortune

import (
	"math/rand"
	"time"
)

func getRandomFortune(luckRank int) string {
	fortunes := []string{
		"Dai-kichi",
		"Kichi",
		"Chuu-kichi",
		"Sho-kichi",
		"Sue-kichi",
		"Kyo",
		"Dai-kyo",
	}
	return fortunes[luckRank]
}

type omikuji struct {
	Fortune string `json:"fortune"`
}

type Dater interface {
	Date() (month time.Month, day int)
}

type DefaultDater struct{}

func (d *DefaultDater) Date() (month time.Month, day int) {
	_, month, day = time.Now().Local().Date()
	return month, day
}

func isNewYear(d Dater) bool {
	month, day := d.Date()
	if month.String() == "January" && (1 <= day && day <= 3) {
		return true
	}
	return false
}

func drawOmikuji(d Dater) *omikuji {
	rand.Seed(time.Now().UnixNano())
	luckRank := rand.Intn(7)
	if isNewYear(d) {
		luckRank = 0
	}
	return &omikuji{getRandomFortune(luckRank)}
}
