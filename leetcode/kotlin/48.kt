class Solution {
  fun rotate(matrix: Array<IntArray>) {
      val n = matrix.size // 4
      var left = 0 // 1
      var right = n-1 // 2

      while(left < right) {
          for(j in (left..right-1)) {  // j: 1
              val leftUp = matrix[left][j] // (1,1): 4
              val rightUp = matrix[j][n-left-1] // (1,2): 8
              val rightDown = matrix[n-left-1][n-j-1] // (2,2): 6
              val leftDown = matrix[n-j-1][left] // (2,1): 3
              matrix[left][j] = leftDown 
              matrix[j][n-left-1] = leftUp
              matrix[n-left-1][n-j-1] = rightUp
              matrix[n-j-1][left] = rightDown
          }
          left++
          right--
      }
      return
  }
}

/*
(0,0) -> (0,2)
(0,1) -> (1,2)
(0,2) -> (2,2)
(1,2) -> (2,1)


(0,1) -> (1,3)
(1,3) -> (3,2)
(i,j) -> (j,n-i)
(3,1) -> (1,0)
*/