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
  fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
      var overflow = 0
      var node1 = l1
      var node2 = l2
      var unionNode = ListNode(-1)
      var dummy = unionNode

      while(node1 != null || node2 != null) {
          var addition = (node1?.`val` ?: 0) + (node2?.`val` ?: 0) + overflow
          if(addition >= 10) {
              overflow = 1
          } else {
              overflow = 0
          }
          addition %= 10

          unionNode.next = ListNode(addition)
          unionNode = unionNode.next
          node1 = node1?.next
          node2 = node2?.next
      }

      if(overflow != 0) {
          unionNode.next = ListNode(overflow)
      }

      return dummy.next
  }
}