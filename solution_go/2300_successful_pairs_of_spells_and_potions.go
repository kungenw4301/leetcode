package solution_go

import "sort"

func successfulPairs(spells []int, potions []int, success int64) []int {
	result := make([]int, len(spells))
	sort.Ints(potions)

	// binary search for success/spell[i]
	for i, v := range spells {
		target := int(success-1)/(v) + 1 // need to round lower bound  y>[success/x] > y[(success-1)/x]
		count := binarySearchGECount(potions, target)
		result[i] = count
	}
	return result
}

func binarySearchGECount(a []int, target int) int {
	n := len(a)
	l := 0
	r := n - 1
	for l <= r {
		mid := (l + r) / 2
		if a[mid] >= target { // find left most index
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	// r would stop in left most
	// eg: 1,2,3,4,6 target=5, r stop at a[4]
	return n - r - 1
}
