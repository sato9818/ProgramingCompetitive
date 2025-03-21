class Solution {
  fun setZeroes(matrix: Array<IntArray>): Unit {
      var firstRow = 1
      for(i in 0 until matrix.size) {
          for(j in 0 until matrix[i].size) {
              if(matrix[i][j] == 0) {
                  if(i == 0) {
                      firstRow = 0
                  } else {
                      matrix[i][0] = 0
                  }
                  matrix[0][j] = 0
              }
          }
      }

      for(j in 1 until matrix[0].size) {
          if(matrix[0][j] == 0) {
              for(i in 0 until matrix.size) {
                  matrix[i][j] = 0
              }
          }
      }

      for(i in 1 until matrix.size) {
          if(matrix[i][0] == 0) {
              for(j in 0 until matrix[0].size) {
                  matrix[i][j] = 0
              }
          }
      }
      if(matrix[0][0] == 0) {
          for(i in 1 until matrix.size) {
              matrix[i][0] = 0
          }
      }

      if(firstRow == 0) {
          for(j in 0 until matrix[0].size) {
              matrix[0][j] = 0
          }
      }
  }
}

/*
1101 (0,2)
1111
0101
1111
val firstRow = 0
(i,j) is 0
(0,i) and (j,0) 0 
*/
// 