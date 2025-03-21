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
  var ans: Int = 0;
  var k: Int = 0;
  fun kthSmallest(root: TreeNode?, k: Int): Int {
      this.k = k
      traverse(root)
      return ans
  }

  fun traverse(node: TreeNode?) {
      if(node == null) {
          return
      }
      if(k<0){
          return 
      }
      traverse(node.left)
      k--
      if(k == 0) {
          ans = node.`val`
          return 
      }

      traverse(node.right)
  }
}

//