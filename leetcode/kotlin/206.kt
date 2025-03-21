/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
  fun reverseList(head: ListNode?): ListNode? {
      if(head == null || head.next == null) {
          return head
      }
      var pointer1: ListNode? = null // 1
      var pointer2 = head // 2

      while(pointer2 != null){
          val next = pointer2.next // 3, 4 // could be null
          pointer2.next = pointer1 // 1 <- 2 3->4->5
          pointer1 = pointer2 // pointer1: 2
          pointer2 = next // pointer2: 3
      }

      return pointer1
  }
}
// node1 -> node2 -> node3 -> node4
// 4
// 3
// 2
// 1