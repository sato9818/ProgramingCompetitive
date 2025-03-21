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

      val freqs = count.entries.sortedByDescending {it.value}
      val maxFreq = freqs[0].value
      var idle = (maxFreq - 1) * n
      for(i in 1 until freqs.size) {
          val freq = freqs[i].value
          idle -= min(maxFreq - 1, freq)        
      }

      
      return max(0, idle) + tasks.size
  }
}

// Time: O(n + klogk) 
// Space: O(k)
// Time: O(n) k = 26
// Space: O(1) k = 26
// maxCount: 5
// n: 3
// A...A...A...A...A
// 1. Set other alphabet to '.'.
// 2. If there is no '.', it means there won't be idle time. So return the tasks.size.
// 3. If there is some '.', it means there will be idle times. So return the tasks.size + idle.

/*
Ex) A, A, A, A, A, B, C, D
n:3
AB..AC..AD..A...A

idle: 9
tasks.size: 8
ans: 17
*/

/*
Ex) A, A, A, A, A, B, B, B, B, B C, D, E, F,
n:2
ABCABDABEABFA(B)

idle: 0
tasks.size: 14
ans: 14
*/

/*
Ex) A, A, A, A, A, B, B, B, B, B C, D, E, F,G
n:2
ABCABDABEABFA(BG)

idle: 0
tasks.size: 14
ans: 14
*/