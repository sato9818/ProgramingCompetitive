/**
 * Example:
 * var ti = Node(5)
 * var v = ti.`val`
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var next: Node? = null
 *     var random: Node? = null
 * }
 */

 class Solution {
  fun copyRandomList(node: Node?): Node? {
      var list1: Node? = node

      while(list1 != null) {
          val node2 = Node(list1.`val`)
          node2.next = list1.random
          list1.random = node2
          list1 = list1.next
      }

      list1 = node
      while(list1 != null) {
          val list2 = list1.random!!
          list2.random = list2.next?.random
          list1 = list1.next
      }

      list1 = node
      val res = list1?.random
      while(list1 != null) {
          val list2 = list1.random!!
          list1.random = list2.next
          list2.next = list1.next?.random
          list1 = list1.next
      }

      // var debug = res
      // while(debug != null) {
      //     println("${debug.`val`} ${debug.random?.`val`}")
      //     debug = debug.next
      // }
      return res
  }
}

/*
hashMap -> key: originalNode, value: newNode

7 -> 13 -> 11 ->  10` -> 1 -> null
v.   v.    v.     v.   v
n.   7.    1.     11.  7
   ^
7 -> 13 -> 11. -> 10 -> 1
   v.    v.     v.    v
   7.    1.     11.   7

Time, Space: O(N) 

1. Create the deep copy of the original node and set the random node of the original node as the next node of new node.
1.2 Replace the random node of the original node with the new node. The new node points to the random node of the new node indirectly.
2. Set the random node of the new node.
3. Set the next node of the new node.
O(n)
O(1)

*/