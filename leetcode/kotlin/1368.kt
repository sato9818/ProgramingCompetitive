// Amazon
class Solution {
  private data class CellCost(
      val x: Int,
      val y: Int,
      val cost: Int
  )

  val moveX = listOf(0,0,1,-1)
  val moveY = listOf(1,-1,0,0)
  fun minCost(grid: Array<IntArray>): Int {
      val queue = PriorityQueue<CellCost>(compareBy{it.cost})
      val m = grid.size
      val n = grid[0].size

      queue.add(CellCost(0,0,0))

      val minCost = MutableList(m) { MutableList(n) { Int.MAX_VALUE } }

      while(queue.isNotEmpty()) {
          val head = queue.poll()
          if(head.x >= m || head.x < 0 || head.y >= n || head.y < 0) {
              continue
          }
          if(minCost[head.x][head.y] != Int.MAX_VALUE) {
              continue
          }
          minCost[head.x][head.y] = head.cost
          for(i in (1..4)){
              val nextX = head.x + moveX[i-1]
              val nextY = head.y + moveY[i-1]
              if(grid[head.x][head.y] == i){
                  queue.add(CellCost(nextX,nextY,head.cost))
              } else {
                  queue.add(CellCost(nextX,nextY,head.cost + 1))
              }
          }
      }

      return minCost[m-1][n-1]
  }
}

// >>>>
// <<<<
// >>>>
// <<<<
// cost[i][j]: the cost to get the cell(i,j)
// 0000
// MMM1
// MMMM
// MMMM
// minHeap: (1,2,1)(1,2,1)(1,1,1)(1,0,1)
// Time: O(n*m*log(n*m))
// Space: O(n*m)