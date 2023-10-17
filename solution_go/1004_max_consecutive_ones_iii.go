package solution_go

func longestOnes(nums []int, k int) int {
	n := len(nums)
	sum := 0 // sum in window
	ans := 0
	for l, r := 0, 0; r < n; r++ {
		sum += nums[r]
		// move left pointer to make number of 0 less than k
		// sum keeps how many 1 exists, eg: 1,[0,0,1,1,0],1
		for (r-l+1)-sum > k {
			sum -= nums[l]
			l++
		}
		// get max window
		ans = max1004(ans, r-l+1)
	}
	return ans
}

func max1004(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
