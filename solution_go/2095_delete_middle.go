package solution_go

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
	if head.Next == nil { // 1->2->nil => 1->nil, remove regularly
		return nil
	}
	// fast ptr move 2-steps while slow ptr 1-step every time
	// slow would point to middle node while fast stop at tail
	fast := head
	slow := head
	var prev *ListNode = nil              // prev -> middle -> post => prev->post
	for fast != nil && fast.Next != nil { // fast.Next.Next could be nil
		fast = fast.Next.Next
		prev = slow
		slow = slow.Next
	}
	// remove middle
	prev.Next = prev.Next.Next
	return head // head not changed
}
