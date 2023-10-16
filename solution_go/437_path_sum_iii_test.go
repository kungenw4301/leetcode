package solution_go

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_pathSum(t *testing.T) {
	treeNum := []interface{}{5, 4, 8, 11, nil, 13, 4, 7, 2, nil, nil, 5, 1}
	tree := buildTree(treeNum)
	walkTree(tree)

	pathCount := pathSum(tree, 22)
	assert.Equal(t, 1, pathCount)
}
