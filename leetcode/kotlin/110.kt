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
  fun isBalanced(root: TreeNode?): Boolean {
      var res = true
      fun height(node: TreeNode?): Int {
          if(node == null) {
              return 0
          }
          val leftHeight = height(node.left)
          val rightHeight = height(node.right)
          if(abs(leftHeight -rightHeight) > 1) {
              res = false
          }
          return max(leftHeight, rightHeight) + 1
      }

      height(root)

      return res
  }
}


// O(n): all nodes
// O(h): tree height