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
  fun diameterOfBinaryTree(root: TreeNode?): Int {
      var res = 0
      fun findLongestPath(node: TreeNode?): Int {
          if(node == null) {
              return 0
          }
          val rightLongestPath = findLongestPath(node.right)
          val leftLongestPath = findLongestPath(node.left)
          res = max(res, rightLongestPath+leftLongestPath)

          return max(rightLongestPath+1, leftLongestPath+1)
      }
      findLongestPath(root)
      return res
  }
}

// O(n): all nodes
// O(h): height of the tree