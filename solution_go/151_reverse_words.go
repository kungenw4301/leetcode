package solution_go

import "strings"

func reverseWords(s string) string {
	// if use strings.Split(), you need to handle multiple continuous space
	strs := strings.Fields(s)
	for i, j := 0, len(strs)-1; i < j; i, j = i+1, j-1 {
		strs[i], strs[j] = strs[j], strs[i]
	}
	return strings.Join(strs, " ")
}
