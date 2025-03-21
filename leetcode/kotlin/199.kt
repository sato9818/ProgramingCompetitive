/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
  fun rightSideView(root: TreeNode?): List<Int> {
      if(root == null) {
          return emptyList()
      }
      val queue = LinkedList<TreeNode>()
      queue.add(root)
      val res = mutableListOf<Int>()

      while(queue.isNotEmpty()) {
          val n = queue.size
          for(i in 0 until n) {
              val node = queue.poll()
              if(i == n-1) {
                  res.add(node.`val`)
              }
              node.left?.let {queue.add(it)}
              node.right?.let {queue.add(it)}
          }
      }

      return res
  }
}

// O(n)
// O(n)