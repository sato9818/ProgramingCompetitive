class Solution {
  fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {
      val graph = MutableList(numCourses) { mutableListOf<Int>() }
      val indegrees = MutableList(numCourses) { 0 }

      prerequisites.forEach { dependency -> 
          graph[dependency[1]!!].add(dependency[0]!!)
          indegrees[dependency[0]!!]++
      }

      val queue: Queue<Int> = LinkedList()
      
      (0..numCourses-1).forEach { i ->
          if(indegrees[i] == 0) {
              queue.add(i)
          }
      }
      
      val canTake = MutableList(numCourses) { false }

      while(queue.isNotEmpty()) {
          val node = queue.poll()
          if(canTake[node] == true) {
              continue
          }
          canTake[node] = true
          graph[node].forEach { 
              indegrees[it]--
              if(indegrees[it] == 0) {
                  queue.add(it)
              }
          }
      }

      canTake.forEach {
          if(!it) return false
      }

      return true
  }
}

// 
// [1,0]
// 1 depends on 0
// 0 -> 1, 1 -> 0, 2 -> 1
// indegrees: 0, 1
// time: O(V + E) V: every vertices, E: every node
// space: O(V + E)