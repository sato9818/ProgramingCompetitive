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
  fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
      if(q == null && p == null) {
          return true
      } else if (q == null || p == null) {
          return false
      } else {
          if(q.`val` == p.`val`) {
              return isSameTree(p?.right, q?.right) && isSameTree(p?.left, q?.left)
          } else {
              return false
          }
      }
  }
}