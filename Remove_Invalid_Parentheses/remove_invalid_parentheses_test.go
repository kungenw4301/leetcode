package leetcode

import (
	"testing"
)

func Test_removeInvalidParentheses(t *testing.T) {
	s := "()())()"
	result := removeInvalidParentheses(s)
	t.Logf("result: %v", result)
}
