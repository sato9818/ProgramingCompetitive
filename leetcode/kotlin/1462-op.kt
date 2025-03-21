class Solution {
  fun checkIfPrerequisite(numCourses: Int, prerequisites: Array<IntArray>, queries: Array<IntArray>): List<Boolean> {
      val adj = MutableList(numCourses) {MutableList(numCourses) {false}}
      for(prerequisite in prerequisites) {
          val prev = prerequisite[0]
          val next = prerequisite[1]
          adj[prev][next] = true
      }

      for(k in 0..numCourses-1) {
          for(i in 0..numCourses-1) {
              for(j in 0..numCourses-1) {
                  adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j])
              }
          }
      }

      val res = mutableListOf<Boolean>()
      for(query in queries) {
          res.add(adj[query[0]][query[1]])
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
// https://qiita.com/rp523/items/8fba3882c4a6ea203757