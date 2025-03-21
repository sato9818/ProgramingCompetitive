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
  fun invertTree(root: TreeNode?): TreeNode? {
      if(root == null) {
          return null
      }
      val node = root
      val right = invertTree(node.right)
      val left = invertTree(node.left)
      node.right = left
      node.left = right
      
      return node
  }
}