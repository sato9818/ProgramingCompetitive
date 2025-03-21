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
  fun reverseKGroup(head: ListNode?, k: Int): ListNode? {
      var slow = head
      var fast = head
      var copyK = k-1
      while(copyK != 0 && fast != null) {
          fast = fast.next
          copyK--
      }

      if(copyK > 0) {
          return head
      }

      var prev: ListNode? = null // 1
      val dummy = ListNode(-1)
      var prevTail = dummy
      while(fast != null) {
          var count = k // 2
          var curHead = slow // 1
          while(count != 0) {
              fast = fast?.next // 
              val next = slow?.next // 3
              slow?.next = prev // 2->1->null
              prev = slow // 2
              slow = next // 3
              count-- // 0
          }
          prevTail.next = prev
          prevTail = curHead!!
          curHead?.next = slow
          curHead = slow
      }

      return dummy.next
  }
}

/*
            pT
                   cH
        p     
dummy -> 2 -> 1  ->  3 <- 4    5 
                    s
                         f
                       

*/