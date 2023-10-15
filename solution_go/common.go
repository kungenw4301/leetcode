package solution_go

import (
	"fmt"
	"strconv"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(nums []interface{}) *TreeNode {
	return sliceToTree(nums, 0)
}

func sliceToTree(nums []interface{}, index int) *TreeNode {
	if index >= len(nums) {
		return nil
	}
	if nums[index] == nil {
		return nil
	}
	node := TreeNode{}
	if val, ok := nums[index].(int); ok {
		node.Val = val
	}
	node.Left = sliceToTree(nums, index*2+1)
	node.Right = sliceToTree(nums, index*2+2)
	return &node
}

func walkTree(root *TreeNode) {
	if root == nil {
		return
	}
	val := root.Val
	left := "nil"
	right := "nil"
	if root.Left != nil {
		left = strconv.Itoa(root.Left.Val)
	}
	if root.Right != nil {
		right = strconv.Itoa(root.Right.Val)
	}

	fmt.Printf("%v -> %v, %v -> %v \n", val, left, val, right)
	if root.Left != nil {
		walkTree(root.Left)
	}
	if root.Right != nil {
		walkTree(root.Right)
	}
}

type ListNode struct {
	Val  int
	Next *ListNode
}
