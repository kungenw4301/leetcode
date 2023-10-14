package solution_go

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) int {
	prefixSumCount := map[int]int{}
	// important: must add a dummy node, otherwise path from root will be filtered, because (cur - 0) not exist
	// see: [5,4,8,11,null,13,4,7,2,null,null,5,1], you will not find 5->4->11->2
	prefixSumCount[0] = 1 // why?
	return dfs(root, 0, targetSum, prefixSumCount)
}

// iterate unique path via DFS
// return how many path valid
func dfs(node *TreeNode, cur int, targetSum int, prefixSumCount map[int]int) int {
	if node == nil {
		return 0
	}
	ans := 0

	// get prefix sum to current node
	cur += node.Val

	// if exist a path that prefix sum equals (cur-target) previously,
	// there must be a sub-path make it equals targetSum
	if v, ok := prefixSumCount[cur-targetSum]; ok {
		ans += v
	}

	prefixSumCount[cur]++ // one more path make (prefixSum == sum)
	// accumulate left child tree
	ans += dfs(node.Left, cur, targetSum, prefixSumCount)
	ans += dfs(node.Right, cur, targetSum, prefixSumCount)

	// backtrace one level, there would one less path whose prefixSum equals cur
	prefixSumCount[cur]--
	return ans
}
