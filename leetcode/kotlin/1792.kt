class Solution {
  fun maxAverageRatio(classes: Array<IntArray>, extraStudents: Int): Double {
      val queue = PriorityQueue<IntArray>(compareByDescending{(it[0]+1).toDouble() / (it[1]+1).toDouble() - it[0].toDouble() / it[1].toDouble()})

      for(c in classes) {
          queue.add(c)
      }

      (0..extraStudents-1).forEach {
          val cls = queue.poll()
          cls[0] += 1
          cls[1] += 1
          queue.add(cls)
      }

      var aveSum = 0.0
      while(queue.isNotEmpty()) {
          val cls = queue.poll()
          aveSum += cls[0].toDouble() / cls[1]
      }

      return aveSum / classes.size
  }
}
// 1/4 -> 2/5 : 0.25 -> 0.4
// 2/4 -> 3/5 : 0.5 -> 0.6
// Time: O(klogn) k: extraStudents
// Space: O(n)