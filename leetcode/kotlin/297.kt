/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

 class Codec() {
	// Encodes a URL to a shortened URL.
    fun serialize(root: TreeNode?): String {
        return preorderTraversal(root)
    }

    private fun preorderTraversal(root: TreeNode?): String {
        if(root == null) {
            return "N#"
        }
        var res = ""
        res += "${root.`val`}#"
        res += preorderTraversal(root.left)
        res += preorderTraversal(root.right)
        return res
    }

    // Decodes your encoded data to tree.
    fun deserialize(data: String): TreeNode? {
        // 1#2#N#N#3#4#N#N#5#N#N#
        val strs = data.split("#")
        var index = 0

        fun createTree(): TreeNode? {
            val num = strs[index]
            index++
            if(num == "N") {
                return null
            }

            val newNode = TreeNode(num.toInt())
            newNode.left = createTree()
            newNode.right = createTree()

            return newNode
        }

        return createTree()
    }
}

// "#11#22"

/**
 * Your Codec object will be instantiated and called as such:
 * var ser = Codec()
 * var deser = Codec()
 * var data = ser.serialize(longUrl)
 * var ans = deser.deserialize(data)
 */

//  1
// 2  3
//   4 5
// 21435
// 12345