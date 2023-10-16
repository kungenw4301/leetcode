package solution_go

func maxOperations(nums []int, k int) int {
	n := len(nums)
	// 1. count how many times one number present
	m := make(map[int]int, n)
	for _, v := range nums {
		if count, ok := m[v]; ok {
			m[v] = count + 1
		} else {
			m[v] = 1
		}
	}

	// 2. for every v, check if k-v exist and remove one if multiple v exist
	result := 0
	for _, v := range nums {
		if m[v] <= 0 { // if no more v remained
			continue
		}
		// remove if exist duplicated num, eg: [3,1,3,4,3], k = 6
		// otherwise you will add same element to sum
		m[v]--
		remain := k - v
		if count, ok := m[remain]; ok {
			if count > 0 { // num exist, k-num exist
				m[remain] = count - 1
				result++
			}
		}
	}
	return result
}

// why we can do this optimization?
// because (num, k-num) present by pair, if we do not encounter num, then would encounter k-num later
func maxOperationsOnePass(nums []int, k int) int {
	n := len(nums)
	// 1. count how many times one number present
	// 2. for every v, check if k-v exist and remove one if multiple v exist
	m := make(map[int]int, n)

	result := 0
	for _, v := range nums {
		remain := k - v
		// num exist, k-num exist
		if count, ok := m[remain]; ok && count > 0 {
			m[remain] = count - 1
			result++

			// do not need to remove current num, because we did not count current num till now
			continue
		}

		// if k-num not exist, we don't have a valid pair, so keep this num
		if count, ok := m[v]; ok {
			m[v] = count + 1
		} else {
			m[v] = 1
		}

	}
	return result
}
