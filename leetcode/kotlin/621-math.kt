class Solution {
  data class PendingTask(
      val count: Int,
      val time: Int,
  )

  fun leastInterval(tasks: CharArray, n: Int): Int {
      val count = mutableMapOf<Char, Int>()
      for(task in tasks) {
          count[task] = count.getOrDefault(task, 0) + 1
      }

      val freqs = count.values
      val maxFreq = freqs.maxOrNull() ?: 0
      var maxCount = 0
      for(freq in freqs) {
          if(maxFreq == freq) {
              maxCount++
          }
      }
      val cand = (1+n) * (maxFreq-1) + maxCount

      
      return max(cand, tasks.size)
  }
}

// Time: O(n + k) 
// Space: O(k)
// Time: O(n) k = 26
// Space: O(1) k = 26
// maxCount: 5
// n: 3

// 1. When there are some idle times
//    AB..|AB..|AB..|AB.. | AB
// = { (1+n)*(maxFreq-1) }+{maxCount}

// 2. When there is no idle time
//  AB|AB|AB|AB | ABCDEF
// = tasks.size

// 3. Compare both possible scenarios