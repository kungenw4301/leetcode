package solution_go

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_maxOperations(t *testing.T) {
	nums := []int{3, 1, 3, 4, 3}
	max := maxOperations(nums, 6)
	assert.Equal(t, 1, max)
}
