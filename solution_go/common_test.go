package solution_go

import (
	"testing"
)

func Test_buildTree(t *testing.T) {
	nums := []interface{}{1, 2, 3, 4, 5, 6, 7}
	tree := buildTree(nums)
	t.Logf("tree")
	walkTree(tree)
}

func Test_buildTree1(t *testing.T) {
	nums := []interface{}{1, 2, 3, 4, nil, nil, nil}
	tree := buildTree(nums)
	t.Logf("tree")
	walkTree(tree)
}
