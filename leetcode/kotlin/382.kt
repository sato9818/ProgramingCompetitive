/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution(val head: ListNode?) {
  fun getRandom(): Int {
      var count = 1
      var node = this.head
      var res = -1
      while(node != null) {
          // take it with 1/count probabillity
          val ramdom = Random.nextInt(0,count)
          if(ramdom == 0) {
              res = node.`val`
          }
          node = node.next
          count++
      }

      return res
  }

}

/**
* Your Solution object will be instantiated and called as such:
* var obj = Solution(head)
* var param_1 = obj.getRandom()
*/

// 1  2    3
//   1/3  1/3
// 1: 1 * 1/2 * 2/3 = 1/3
// 2: 1/2 * 2/3 = 1/3
// 3: 1/3
