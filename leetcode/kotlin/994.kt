class Solution {
  data class Cell(
      val i: Int,
      val j: Int,
  )
  fun orangesRotting(grid: Array<IntArray>): Int {
      val row = grid.size
      val column = grid[0].size
      val queue = LinkedList<Cell>()

      for(i in 0 until row) {
          for(j in 0 until column) {
              if(grid[i][j] == 2) {
                  queue.add(Cell(i,j))
              }
          }
      }

      var time = 0
      val moveI = listOf(0,0,1,-1)
      val moveJ = listOf(1,-1,0,0)

      while(queue.isNotEmpty()) {
          val queueSize = queue.size
          var changed = false
          (0..queueSize-1).forEach {
              val cell = queue.poll()
              for(i in 0 until 4) {
                  val nextI = cell.i + moveI[i]
                  val nextJ = cell.j + moveJ[i]
                  if(nextI < 0 || nextI >= row || nextJ < 0 || nextJ >= column) {
                      continue
                  }
                  if(grid[nextI][nextJ] == 1) {
                      changed = true
                      grid[nextI][nextJ] = 2
                      queue.add(Cell(nextI, nextJ))
                  }
              }
          }
          if(changed) {
              time++
          }
      }

      for(i in 0 until row) {
          for(j in 0 until column) {
              if(grid[i][j] == 1) {
                  return -1
              }
          }
      }

      return time
  }
}

/*
[2,2,1]
[2,1,0]
[0,1,1]

minute: 4
queue: (1,0) (0,1)

Time: O(m*n)
Space: O(m*n)

1. Search all rotten oranges and put them into queue.
2. Increment `time`. Pop all cells in queue, see if there is fresh orange in the adjecent cell. 
2.1 If so, change to rotten orange and push the cell into queue.
3. If there is fresh orange in th gird, return -1. Otherwise, return `time`.
*/