/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := new(ListNode)
    tail := head
    pre := tail
    flag := 0

    for l1 != nil && l2 != nil {
        sum := l1.Val + l2.Val + flag
        tail.Val = sum % 10
        flag = sum / 10
        l1 = l1.Next

        l2 = l2.Next

        pre, tail = next(pre, tail)
    }
    if l1 != nil || l2 != nil {
        for l1 != nil {
            sum := l1.Val + flag
            tail.Val = sum % 10
            flag = sum / 10

            l1 = l1.Next
            pre, tail = next(pre, tail)
        }
        for l2 != nil {
            sum := l2.Val + flag
            tail.Val = sum % 10
            flag = sum / 10

            l2 = l2.Next
            pre, tail = next(pre, tail)
        }
    }
    if flag > 0 {
        tail.Val = flag
        pre, tail = next(pre, tail)
    }
    pre.Next = nil
    return head
}

func next(pre, tail *ListNode) (*ListNode, *ListNode){
    pre = tail
    p := new(ListNode)
    tail.Next = p
    tail = p
    return pre, tail
}

