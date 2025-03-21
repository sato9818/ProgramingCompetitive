class Solution {
  // ^ > v <
  val moveX = listOf(0, 1, 0, -1)
  val moveY = listOf(-1, 0, 1, 0)
  fun numIslands(grid: Array<CharArray>): Int {
      val maxY = grid.size
      val maxX = grid[0].size
      var count = 0
      fun findConnectedLands(x: Int, y: Int) {
          if(x >= maxX || x < 0 || y < 0 || y >= maxY) {
              return 
          }
          if(grid[y][x] == '#' || grid[y][x] == '0') {
              return
          }
          if(grid[y][x] == '1') {
              grid[y][x] = '#'
          }

          (0..3).forEach { i ->
              findConnectedLands(x + moveX[i], y + moveY[i])
          }
      }

      grid.forEachIndexed { yi, row ->
          row.forEachIndexed { xi, element ->
              if(element == '1') {
                  findConnectedLands(xi, yi)
                  count++
              }
          }
      }

      return count
  }
}
// x: horizotal
// y: vertical
// grid[y][x]
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]