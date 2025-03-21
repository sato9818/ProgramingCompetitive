class Solution {
  fun dailyTemperatures(temperatures: IntArray): IntArray {
      val res = IntArray(temperatures.size)
      val stack = mutableListOf<Pair<Int,Int>>()
      for((i, t) in temperatures.withIndex()) {
          while(stack.size != 0 && stack.last().first < t) {
              val tem = stack.last()
              res[tem.second] = i - tem.second
              stack.removeLast()
          }
          stack.add(t to i)
      }
      return res
  }
}

// Time: O(n)
// Space: O(n)