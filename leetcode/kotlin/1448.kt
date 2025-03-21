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
  fun goodNodes(root: TreeNode?): Int {
      var res = 0
      fun findGoodNodes(node: TreeNode?, curMax: Int) {
          if(node == null) {
              return
          }

          val maxVal = if(node.`val` >= curMax) {
              res++
              node.`val`
          } else {
              curMax
          }

          findGoodNodes(node.left, maxVal)
          findGoodNodes(node.right, maxVal)
      }

      findGoodNodes(root, Int.MIN_VALUE)
      return res
  }
}

// O(n)
// O(h)