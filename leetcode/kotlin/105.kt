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
  // private val inorderIndexMap = mutableMapOf<Int, Int>()
  // fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
  //     inorder.forEachIndexed { index, value ->
  //         inorderIndexMap.put(value, index)
  //     }

  //     var preorderIndex = 0

  //     fun createBinaryTreeInternal(left: Int, right: Int): TreeNode? {
  //         if(left > right) {
  //             return null
  //         }

  //         val value = preorder[preorderIndex]
  //         var inorderIndex = inorderIndexMap[value]!!
  //         preorderIndex++
  //         val root = TreeNode(value)
  //         root.left = createBinaryTreeInternal(left, inorderIndex-1)
  //         root.right = createBinaryTreeInternal(inorderIndex + 1, right)
  //         return root
  //     }
  //     return createBinaryTreeInternal(0, inorder.size-1)
  // }

  fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
      var preorderIndex = 0
      var inorderIndex = 0
      fun createBinaryTree(parentVal: Int): TreeNode? {
          if(preorderIndex >= preorder.size || inorderIndex >= inorder.size) {
              return null
          }

          val preorderVal = preorder[preorderIndex]
          val inorderVal = inorder[inorderIndex]

          if(inorderVal == parentVal) {
              inorderIndex++
              return null
          }
          
          val root = TreeNode(preorderVal)
          preorderIndex++
          root.left = createBinaryTree(root.`val`)
          root.right = createBinaryTree(parentVal)
          return root
      }
      
      return createBinaryTree(10000000)
  }

  fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
    var preIndex = 0
    var inIndex = 0

    fun buildTreeInternal(parent: Int): TreeNode? {
        if(inIndex >= inorder.size) {
            return null
        }

        if(inorder[inIndex] == parent) {
            inIndex++
            return null
        }

        if(preIndex >= preorder.size) {
            return null
        }
        val root = TreeNode(preorder[preIndex++])
        val left = buildTreeInternal(root.`val`)
        val right = buildTreeInternal(parent)
        root.left = left
        root.right = right
        return root
    }

    return buildTreeInternal(100000)
}
}

// preorder = [3,9,4,20,15,7], inorder = [9,4,3,15,20,7]