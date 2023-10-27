package solution_go

func removeStars(s string) string {
	result := make([]rune, 0) // consider UTF-8, rune is code point
	for _, v := range s {
		if v == '*' {
			// stack pop, [0, len-1) => [0, len-2]
			result = result[:len(result)-1]
		} else {
			// stack push
			result = append(result, v)
		}
	}
	return string(result)
}
