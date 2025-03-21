class UnionFind(n: Int) {
  val size: List<Int>(n){1}
  val parent: List<Int>{n} { it }

  private fun parent(node: Int): Int {
      var cur = node
      while(cur != parent[cur]) {
          parent[cur] = parent[parent[cur]]
          cur = parent[cur]
      }
      return cur
  }

  fun union(n1: Int, n2: Int) {
      val p1 = parent(n1)
      val p2 = parent(n2)
      if(p1 == p2) {
          return 
      } else {
          if(size[n1] > size[n2]) {
              parent[n2] = p1
          } else {
              parent[n1] = p2
          }
          size[n1] = size[n1] + size[n2]
          size[n2] = size[n1]
      }
  }
}