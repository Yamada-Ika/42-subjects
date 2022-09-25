package fortune_test

import (
	"reflect"
	"testing"
	"time"

	"example.com/ex00/fortune"
)

func Test_drawOmikuji(t *testing.T) {
	type args struct {
		d *MockDater
	}
	tests := []struct {
		name string
		args args
		want *fortune.ExportOmikuji
	}{
		// TODO: Add test cases.
		{"new year", args{&MockDater{}}, &fortune.ExportOmikuji{"Dai-kichi"}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fortune.ExportDrawOmikuji(tt.args.d); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("drawOmikuji() = [%v], want [%v]", got, tt.want)
			}
		})
	}
}

type MockDater struct{}

func (m *MockDater) Date() (month time.Month, day int) {
	return (time.Month)(1), 1
}
