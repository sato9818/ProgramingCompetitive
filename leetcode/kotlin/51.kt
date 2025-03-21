class Solution {
  fun solveNQueens(n: Int): List<List<String>> {
      val res = mutableListOf<List<String>>()
      val board = MutableList<CharArray>(n) { CharArray(n) {'.'} }
      val visitedColumn = MutableList<Boolean>(n) {false}
      val posDiag = MutableList<Boolean>(2*n) {false}
      val negDiag = MutableList<Boolean>(2*n) {false}
      fun dfs(row: Int) {
          if(row == n) {
              res.add(board.map{String(it)})
              return 
          }
          for(column in 0 until n) {
              if(visitedColumn[column] || 
                  posDiag[row-column+n] || 
                  negDiag[n-1-column-row+n]) {
                  continue
              }

              visitedColumn[column] = true
              posDiag[row-column+n] = true
              negDiag[n-1-column-row+n] = true
              board[row][column] = 'Q'
              dfs(row+1)
              visitedColumn[column] = false
              posDiag[row-column+n] = false
              negDiag[n-1-column-row+n] = false
              board[row][column] = '.'
          }
      }
      dfs(0)

      return res
  }
}

/*
Time: O(n!)
Extra Space: O(n*n) 
visitedRow[n]
visitedColumn[n]
3*3
(0,n-2) (1,n-3) 2
(0,n-1) (1,n-2) (2,n-2) 1
(0,n)0
*/