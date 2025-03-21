class Solution {
  val moveX = listOf(0,1,0,-1)
  val moveY = listOf(1,0,-1,0)
  fun pacificAtlantic(heights: Array<IntArray>): List<List<Int>> {
      val lenX = heights.size
      val lenY = heights[0].size
      var canGoPacific = MutableList(lenX) { MutableList<Boolean>(lenY) {false}}
      var canGoAtlantic = MutableList(lenX) { MutableList<Boolean>(lenY) {false}}

      fun traverseFromPacific(x: Int, y: Int, prevHeight: Int) {
          if(x < 0 || y < 0 || x >= lenX || y >= lenY) {
              return
          }
          
          if(canGoPacific[x][y] == true) {
              return
          }

          if(prevHeight > heights[x][y]) {
              return
          }

          canGoPacific[x][y] = true

          (0..3).forEach { i ->
              traverseFromPacific(x + moveX[i], y + moveY[i], heights[x][y])
          }
      }

      fun traverseFromAtlantic(x: Int, y: Int, prevHeight: Int) {
          if(x < 0 || y < 0 || x >= lenX || y >= lenY) {
              return
          }
          
          if(canGoAtlantic[x][y] == true) {
              return
          }

          if(prevHeight > heights[x][y]) {
              return
          }

          canGoAtlantic[x][y] = true

          (0..3).forEach { i ->
              traverseFromAtlantic(x + moveX[i], y + moveY[i], heights[x][y])
          }
      }

      (0..lenX-1).forEach {
          traverseFromPacific(it, 0, 0)
          traverseFromAtlantic(it, lenY-1, 0)
      }

      (0..lenY-1).forEach {
          traverseFromPacific(0, it, 0)
          traverseFromAtlantic(lenX-1, it, 0)
      }

      val ans = mutableListOf<List<Int>>()

      (0..lenX-1).forEach { i ->
          (0..lenY-1).forEach { j ->
              if(canGoPacific[i][j] == true && canGoAtlantic[i][j] == true) {
                  ans.add(listOf(i,j))
              }
          }
      }

      return ans
  }
}

// [1,2,2,3,5]
// [3,2,3,4,4]
// [2,4,5,3,1]
// [6,7,1,4,5]
// [5,1,1,2,4]
// time: O(m*n*m*n)
// O(n*m) Create `var canGoPacific`
// O(n*m) Create `var canGoAtlantic`
// space O(n*m)