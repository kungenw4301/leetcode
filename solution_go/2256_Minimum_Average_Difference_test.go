package solution_go

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_minimumAverageDifference(t *testing.T) {
	a := []int{2, 5, 3, 9, 5, 3}
	result := minimumAverageDifference(a)
	t.Logf("result: %v", result)
}

func Test_minimumAverageDifference0(t *testing.T) {
	a := []int{0}
	result := minimumAverageDifference(a)
	t.Logf("result: %v", result)
	assert.Equal(t, 1, result)
}

func Test_minimumAverageDifference1(t *testing.T) {
	a := []int{4, 2, 0}
	result := minimumAverageDifference(a)
	t.Logf("result: %v", result)
	assert.Equal(t, 2, result)
}
