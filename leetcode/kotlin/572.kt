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
  fun isSubtree(root: TreeNode?, subRoot: TreeNode?): Boolean {
      if(root == null && subRoot == null) {
          return true
      }

      if(subRoot == null) {
          return true
      }

      if(root == null) {
          return false
      }

      if(root.`val` == subRoot.`val`) {
          if(isSameTree(root, subRoot)) {
              return true
          }
      }

      return isSubtree(root.right, subRoot) || isSubtree(root.left, subRoot)
  }

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