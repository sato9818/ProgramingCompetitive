class UnionFind(capacity: Int) {
  val size = IntArray(capacity)
  val parent = IntArray(capacity) {it}

  fun parent(n: Int): Int {
      var node = n
      while(node != parent[node]) {
          node = parent[node]
          parent[node] = parent[parent[node]]
      }
      return node
  }

  fun union(n1: Int, n2: Int): Boolean {
      val p1 = parent(n1)
      val p2 = parent(n2)
      if(p1==p2) {
          return false
      }
      val size1 = size[p1]
      val size2 = size[p2]
      if(size1 > size2) {
          parent[p2] = p1
          size[p1] = size1+size2
      } else {
          parent[p1] = p2
          size[p2] = size1+size2
      }
      return true
  }
}

class Solution {
  fun findRedundantConnection(edges: Array<IntArray>): IntArray {
      val uf = UnionFind(edges.size)
      for(edge in edges) {
          if(!uf.union(edge[0] - 1, edge[1] - 1)){
              return edge
          }
      }
      return intArrayOf()
  }
}

// Time: O(n)
// Space: O(n)