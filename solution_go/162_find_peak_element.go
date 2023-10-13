package solution_go

func findPeakElement(nums []int) int {
	n := len(nums)

	l := 0
	r := n - 1
	for l < r { // 二分查找优化，丢弃没有极值的一边
		i := (l + r) / 2
		if nums[i] > nums[i+1] { // i 下降，极值在左侧
			r = i
		} else { // 上升，右侧
			l = i + 1
		}
	}
	return r
}
