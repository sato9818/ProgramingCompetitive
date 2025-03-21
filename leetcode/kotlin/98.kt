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
  fun isValidBST(root: TreeNode?): Boolean {
      return isValidSubBST(null, null, root)
  }

  private fun isValidSubBST(mx: Int?, mn: Int?, head: TreeNode?): Boolean {
      if(head == null) {
          return true
      }

      val isValid = mx?.let {
          head.`val` < mx
      } ?: true 
      &&
      mn?.let {
          head.`val` > mn
      } ?: true 

      if(isValid){
          return isValidSubBST(head.`val`, mn, head.left) 
              && isValidSubBST(mx, head.`val`, head.right)
      } else{
          return false
      }
  }
}

//   5
//  4  6
//    3 7