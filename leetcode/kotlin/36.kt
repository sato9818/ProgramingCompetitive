class Solution {
  fun isValidSudoku(board: Array<CharArray>): Boolean {
      for(row in 0 until board.size) {
          if(!validRow(board, row)) {
              return false
          }
      }

      for(column in 0 until board.size) {
          if(!validColumn(board, column)) {
              return false
          }
      }

      for(row in 0 until board.size step 3) {
          for(column in 0 until board.size step 3) {
              if(!validBox(board,row,column)) {
                  return false
              }
          }
      }

      return true
  }

  private fun validBox(board: Array<CharArray>, i: Int, j: Int): Boolean {
      var bitmask = 0
      for(di in (0..2)) {
          for(dj in (0..2)) {
              if(board[i+di][j+dj] == '.') {
                  continue;
              }
              val num = (1 shl board[i+di][j+dj].digitToInt())
              if((num and bitmask) >= 1) {
                  return false
              }
              bitmask += num
          }
      }
      return true
  }

  private fun validColumn(board: Array<CharArray>, column: Int): Boolean {
      var bitmask = 0
      for(i in 0 until board.size) {
          if(board[i][column] == '.') {
              continue;
          }
          val num = (1 shl board[i][column].digitToInt())
          if((num and bitmask) >= 1) {
              return false
          }
          bitmask += num
      }
      return true
  }
  

  private fun validRow(board: Array<CharArray>, row: Int): Boolean {
      var bitmask = 0
      for(j in 0 until board.size) {
          if(board[row][j] == '.') {
              continue;
          }
          val num = (1 shl board[row][j].digitToInt())
          if((num and bitmask) >= 1) {
              return false
          }
          bitmask += num
      }
      return true
  }
}