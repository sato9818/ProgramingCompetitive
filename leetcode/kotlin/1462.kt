class Solution {
  fun checkIfPrerequisite(numCourses: Int, prerequisites: Array<IntArray>, queries: Array<IntArray>): List<Boolean> {
      val graph = MutableList(numCourses) {mutableListOf<Int>()}
      val indegrees = MutableList(numCourses) { 0 }
      val depended = mutableMapOf<Int, MutableSet<Int>>()
      for(prerequisite in prerequisites) {
          val prev = prerequisite[0]
          val next = prerequisite[1]
          graph[prev].add(next)
          indegrees[next]++
      }

      val queue: Queue<Int> = LinkedList()
      for(v in 0..numCourses-1) {
          depended[v] = mutableSetOf<Int>()
          if(indegrees[v] == 0) {
              queue.add(v)
          }
      }

      // O(V(V+E))
      while(queue.isNotEmpty()) {
          val v = queue.poll()
          for(next in graph[v]) {
              indegrees[next]--
              depended[next]!!.add(v)
              depended[next]!!.addAll(depended[v]!!)
              if(indegrees[next] == 0) {
                  queue.add(next)
              }
          }
      }

      val res = mutableListOf<Boolean>()
      for(query in queries) {
          if(query[0] in depended[query[1]]!!) {
              res.add(true)
          } else {
              res.add(false)
          }
      }


      return res
  }
}

// Brute Force
// Time: O(N*(V+E))
// Space: O(V+E)

// Optimized
// Time: O(V(V+E) + m)
// Space: O(V^2+E + m)
// depend[i][j]: whether i depends on j or not O(V^2)

// We can use Floyd Warshall Algorithm
// Time: O(V^3 + E + m)
// Space: O(V^2 + m)