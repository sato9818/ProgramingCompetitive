class Solution {
  data class Height(
      val height: Int,
      val index: Int,
  )
  fun largestRectangleArea(heights: IntArray): Int {
      val stack = mutableListOf<Height>()
      var res = 0
      for((i, height) in heights.withIndex()) {
          var minIndex = -1
          while(stack.size != 0 && stack.last().height > height) {
              res = max((i - stack.last().index) * stack.last().height, res)
              minIndex = stack.last().index
              stack.removeLast()
          }
          if(minIndex == -1) {
              stack.add(Height(height, i))
          } else {
              stack.add(Height(height, minIndex))
          }
      }

      while(stack.isNotEmpty()) {
          res = max((heights.size - stack.last().index) * stack.last().height, res)
          stack.removeLast()
      }
      return res
  }
}

// Time: O(n)
// Space: O(n)