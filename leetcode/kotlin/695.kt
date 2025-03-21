class UnionFind(capacity: Int) {
  val size = MutableList(capacity) { 1 }
  val parent = MutableList(capacity) { it }

  fun parent(node: Int): Int {
      var n1 = node
      // For speed up
      while(parent[n1] != n1) {
          n1 = parent[n1]
          parent[n1] = parent[parent[n1]]
      }

      return n1
  }

  fun union(n1: Int, n2: Int): Boolean {
      val p1 = parent(n1)
      val p2 = parent(n2)
      if(p1 == p2) {
          return false
      }
      val size1 = size[p1]
      val size2 = size[p2]
      if(size1 > size2) {
          parent[p2] = p1
          size[p1] = size1 + size2
      } else {
          parent[p1] = p2
          size[p2] = size1 + size2
      }
      
      return true
  }

  fun getSize(node: Int): Int {
      return size[parent(node)]
  }
}
class Solution {
  fun maxAreaOfIsland(grid: Array<IntArray>): Int {
      val n = grid.size
      val m = grid[0].size
      val uf = UnionFind(n*m)

      val moveI = listOf(0,0,1,-1)
      val moveJ = listOf(1,-1,0,0)

      var res = 0
      for(i in 0 until n) {
          for(j in 0 until m) {
              if(grid[i][j] == 0) {
                  continue
              }
              if(i < n-1 && grid[i+1][j] == 1) {
                  uf.union(i*m+j, (i+1)*m+j)
              }
              if(j < m-1 && grid[i][j+1] == 1) {
                  uf.union(i*m+j, i*m+(j+1))
              }
              res = max(res, uf.getSize(i*m+j))
          }
      }
      return res
  }
}

// Time: O(n*m)
// Space: O(n*m)