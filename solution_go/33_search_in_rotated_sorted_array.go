package solution_go

func searchInRotatedArray(nums []int, target int) int {
	n := len(nums)
	l := 0
	h := n - 1

	for l <= h { // num[l] == num[h]
		mid := (l + h) / 2
		if nums[mid] == target {
			return mid
		}
		// note!!! it's kind like recursion, mid element always split it into 2 array,
		// one part would be ordered, another would be rotated sub-array
		// use <=, because [1,3,] target=3
		if nums[0] <= nums[mid] { // [0, l] asc
			if nums[0] <= target && target < nums[mid] { // search in normal ascending array
				h = mid - 1
			} else {
				// drop [0, l], move into smaller range
				l = mid + 1
			}
		} else { // [0, l] would be rotated sub array, find other half
			if nums[mid] < target && target <= nums[n-1] {
				l = mid + 1
			} else {
				h = mid - 1
			}
		}
	}
	// if found, answer should be returned by mid
	return -1
}
