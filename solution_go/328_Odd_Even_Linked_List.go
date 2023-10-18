package solution_go

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	// use two pointer: odd/ even
	// use odd pointer to link even node, even pointer to link odd node

	if head == nil {
		return head
	}

	// save even head, do not need to save odd head, because head == oddHead
	evenHead := head.Next

	odd := head
	even := head.Next
	for even != nil && even.Next != nil {
		odd.Next = even.Next // odd -> odd1
		odd = even.Next      // move odd

		even.Next = odd.Next // even -> even1
		even = odd.Next
		// till now, we linked two even node, two odd node
	}
	odd.Next = evenHead // by the end, odd point to last odd node
	return head
}
