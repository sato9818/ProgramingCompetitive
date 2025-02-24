class Solution {
  fun minTrioDegree(n: Int, edges: Array<IntArray>): Int {
      val graph = MutableList<MutableSet<Int>>(n) {mutableSetOf<Int>()}
      val count = MutableList(n){0}

      for(edge in edges) {
          graph[edge[0]-1].add(edge[1]-1)
          graph[edge[1]-1].add(edge[0]-1)
          count[edge[0]-1]++
          count[edge[1]-1]++
      }

      var res = Int.MAX_VALUE

      for(n1 in 0..n-1) {
          for(n2 in graph[n1]) {
              for(n3 in graph[n2]) {
                  if(n3 !in graph[n1]) continue
                  res = min(res, count[n1] + count[n2] + count[n3] - 6)
              }
          }
      }

      return if(res == Int.MAX_VALUE) {
          -1
      } else {
          res
      }
  }
}

// Time: O(n^3)
// Space: O(n)