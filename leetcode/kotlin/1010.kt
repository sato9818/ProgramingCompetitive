class Solution {
  fun numPairsDivisibleBy60(time: IntArray): Int {
      val counter = mutableMapOf<Int, Int>()
      var res = 0
      for(second in time) {
          val reminder = second % 60
          res += counter.getOrDefault((60-reminder) % 60, 0)
          counter[reminder] = counter.getOrDefault(reminder, 0) + 1
      }

      return res
  }
}
// time: O(N)
// space: O(1)
