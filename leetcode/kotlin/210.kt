class Solution {
  fun findOrder(numCourses: Int, prerequisites: Array<IntArray>): IntArray {
      val graph = MutableList(numCourses) {mutableListOf<Int>()}
      val indegrees = MutableList(numCourses) { 0 }
      for(prerequisite in prerequisites) {
          val a = prerequisite[0]
          val b = prerequisite[1]
          graph[b].add(a)
          indegrees[a]++
      }

      val queue: Queue<Int> = LinkedList()
      val res = mutableListOf<Int>()
      for(v in 0..numCourses-1) {
          if(indegrees[v] == 0) {
              queue.add(v)
          }
      }

      while(queue.isNotEmpty()) {
          val v = queue.poll()
          res.add(v)
          for(next in graph[v]) {
              indegrees[next]--
              if(indegrees[next] == 0) {
                  queue.add(next)
              }
          }
      }

      if(res.size == numCourses) {
          return res.toIntArray()
      } else {
          return intArrayOf()
      }
  }
}

// b -> a
// Time: O(V + E) V: numCourses, E: the number of prerequisites
// Space: O(V + E)