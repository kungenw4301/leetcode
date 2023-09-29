package leetcode

// check if all paired
func isValid(s string) bool {
	count := 0
	for _, v := range s {
		if v == '(' { // check left first
			count++
		}
		if v == ')' { // erase one left parentheses
			count--
			if count < 0 { // if ) remained, invalid
				return false
			}
		}
	}
	return count == 0 // if ( remainded, invalid, must be balanced
}

func removeInvalidParentheses(s string) []string {
	// count unpaired parentheses
	l := 0
	r := 0
	for _, v := range s {
		if v == '(' {
			l += 1
		} else if v == ')' {
			if l == 0 {
				r += 1
			} else {
				l--
			}
		}

	}

	ans := make([]string, 0)
	// remove one, search
	dfs(s, 0, l, r, &ans)
	return ans
}

func dfs(s string, start int, l int, r int, ans *[]string) {
	// if no more parentheses to remove, and valid, it's one anwser
	if l == 0 && r == 0 {
		if isValid(s) {
			*ans = append(*ans, s) // ans must be reference or global, otherwise the change will disappear
			return
		}
	}

	for i := start; i < len(s); i++ {
		// if consecutive parentheses, remove only one
		if i != start && s[i] == s[i-1] {
			continue
		}
		// 如果剩余的字符无法满足去掉的数量要求，直接返回
		if l+r > len(s)-i {
			return
		}

		str := s[:i] + s[i+1:] // remove char to get new string
		if r > 0 && s[i] == ')' {
			dfs(str, i, l, r-1, ans)
		} else if l > 0 && s[i] == '(' {
			dfs(str, i, l-1, r, ans)
		}
	}
}
