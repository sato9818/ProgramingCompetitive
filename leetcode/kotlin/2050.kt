class Solution {
  fun minimumTime(n: Int, relations: Array<IntArray>, time: IntArray): Int {
      val graph = MutableList(n) {mutableListOf<Int>()}
      val indegrees = MutableList(n) { 0 }
      val startMonth = MutableList(n) { 0 }
      for(relation in relations) {
          val prev = relation[0] - 1
          val next = relation[1] - 1
          graph[prev].add(next)
          indegrees[next]++
      }

      val queue: Queue<Int> = LinkedList()
      var minMonth = 0
      for(v in 0..n-1) {
          if(indegrees[v] == 0) {
              queue.add(v)
          }
      }

      while(queue.isNotEmpty()) {
          val v = queue.poll()
          minMonth = max(startMonth[v] + time[v], minMonth)
          for(next in graph[v]) {
              indegrees[next]--
              startMonth[next] = max(startMonth[v] + time[v], startMonth[next])
              if(indegrees[next] == 0) {
                  queue.add(next)
              }
          }
      }

      return minMonth
  }
}

// start[i]: when can we take course i
// minMonth: 
// Time: O(V + E) V: numCourses, E: the number of prerequisites
// Space: O(V + E)