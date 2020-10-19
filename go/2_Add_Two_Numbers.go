package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{Next: l2}
	tail := head
	flag := 0

	for ; l1 != nil; l1 = l1.Next {
		if tail.Next == nil {
			tail.Next = &ListNode{}
		}
		tail = tail.Next
		sum := l1.Val + tail.Val + flag
		flag = sum / 10
		tail.Val = sum % 10
	}
	for tail.Next != nil {
		tail = tail.Next
		sum := tail.Val + flag
		flag = sum / 10
		tail.Val = sum % 10
	}

	if flag > 0 {
		if tail.Next == nil {
			tail.Next = &ListNode{}
		}
		tail.Next.Val = flag
	}

	return head.Next
}
