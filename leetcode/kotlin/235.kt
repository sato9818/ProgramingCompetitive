/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        var node = root
        p!!
        q!!
        while(node != null) {
            if(node.`val` > p.`val` && node.`val` > q.`val`) {
                node = node.left
            } else if(node.`val` < p.`val` && node.`val` < q.`val`) {
                node = node.right
            } else if(node == p || node == q) {
                return node
            } else {
                return node
            }
        }
        return null
    }
}