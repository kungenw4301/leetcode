package solution_go

import "math"

func minimumAverageDifference(nums []int) int {
	// total sum never change: sum(0, i) + sum(i+1, n-1) = total
	if len(nums) <= 1 {
		return 0
	}
	total := 0
	for _, v := range nums {
		total += v
	}

	// for any i, prefixSum => sum[i] = sum[i-1] + nums[i]
	// suffixSum = total - prefixSum
	prefixSum := 0
	suffixSum := total - prefixSum
	n := len(nums)
	minDiff := math.MaxInt
	index := -1
	for i, v := range nums {
		prefixSum += v
		suffixSum = total - prefixSum
		diff := math.MaxInt
		if i == n-1 {
			// special case, suffixAvg = suffixSum / 0, panic
			diff = prefixSum / (i + 1)
		} else {
			diff = absolute(prefixSum/(i+1) - suffixSum/(n-i-1))
		}

		if diff < minDiff {
			minDiff = diff
			index = i
		}
	}
	return index
}

func absolute(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
