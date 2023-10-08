package solution_go

import "math"

func increasingTriplet(nums []int) bool {
	// two-way iteration
	// for index i, get min for left, max for right
	n := len(nums)
	leftMin := make([]int, n)
	rightMax := make([]int, n)

	// get min, you need keep only min for one element
	leftMin[0] = nums[0]
	for i := 1; i < n; i++ {
		leftMin[i] = min(leftMin[i-1], nums[i])
	}

	rightMax[n-1] = nums[n-1]
	for i := n - 2; i >= 1; i-- {
		rightMax[i] = max(rightMax[i+1], nums[i])
	}

	// do not need to be continuous
	for i := 1; i < n-1; i++ {
		if nums[i] > leftMin[i-1] && nums[i] < rightMax[i+1] {
			return true
		}
	}
	return false
}

func increasingTripletGreed(nums []int) bool {
	small := math.MaxInt
	mid := math.MaxInt

	n := len(nums)
	for i := 0; i < n; i++ {
		if nums[i] <= small {
			small = nums[i]
		} else if nums[i] <= mid {
			mid = nums[i]
		} else if nums[i] > mid {
			return true
		}
	}
	return false
}

func min(a int, b int) int {
	if a >= b {
		return b
	} else {
		return a
	}
}

func max(a int, b int) int {
	if a <= b {
		return b
	} else {
		return a
	}
}
