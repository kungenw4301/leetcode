package solution_go

import "testing"

func Test_findPeakElement(t *testing.T) {
	nums := []int{1, 2, 1, 3, 5, 6, 4}
	result := findPeakElement(nums)
	t.Logf("result: %v", result)
}

func Test_findPeakElement1(t *testing.T) {
	nums := []int{1}
	result := findPeakElement(nums)
	t.Logf("result: %v", result)
}
