class Solution {
  fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
      val n = matrix.size
      val m = matrix[0].size
      var left = 0
      var right = n*m-1
      while(left <= right) {
          val mid = (left + right) / 2
          val row = mid / m 
          val column = mid % m
          if(matrix[row][column] == target) {
              return true
          } else if(matrix[row][column] > target) {
              right = mid-1
          } else {
              left = mid+1
          }
      }
      return false
  }
}
/*
mid = 10

Time: O(log(m*n))
Space: O(1)
*/
