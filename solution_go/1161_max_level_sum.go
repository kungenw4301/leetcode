package solution_go

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	// keep only current level
	queue := []*TreeNode{root}
	result := 1

	maxSum := root.Val
	for level := 1; len(queue) > 0; level++ {
		tmp := queue
		sum := 0
		queue = nil
		for _, node := range tmp {
			sum += node.Val
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		if sum > maxSum {
			maxSum = sum
			result = level
		}
	}
	return result
}
