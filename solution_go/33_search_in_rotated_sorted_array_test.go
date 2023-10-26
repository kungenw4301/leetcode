package solution_go

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_searchInRotatedArray(t *testing.T) {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	target := 0
	result := searchInRotatedArray(nums, target)
	assert.Equal(t, 4, result)
}

func Test_searchInRotatedArray0(t *testing.T) {
	nums := []int{1, 3}
	target := 0
	result := searchInRotatedArray(nums, target)
	assert.Equal(t, -1, result)
}

func Test_searchInRotatedArray1(t *testing.T) {
	nums := []int{1, 3}
	target := 3
	result := searchInRotatedArray(nums, target)
	assert.Equal(t, 1, result)
}
