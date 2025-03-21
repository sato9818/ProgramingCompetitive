class Solution {
  fun spiralOrder(matrix: Array<IntArray>): List<Int> {
      val res = mutableListOf<Int>()
      val row = matrix.size
      val column = matrix[0].size
      var right = column // 1
      var bottom = row // 3
      var left = 0 // 0
      var up = 0 // 0
      while(left < right && up < bottom) {
          for(j in left until right) {
              res.add(matrix[up][j])
          }
          up++
          for(i in up until bottom) {
              res.add(matrix[i][right-1])
          }
          right--

          if(bottom <= up || left >= right) {
              break
          }

          for(j in right-1 downTo left) {
              res.add(matrix[bottom-1][j])
          }
          bottom--

          for(i in bottom-1 downTo up) {
              res.add(matrix[i][left])
          }
          left++
      }

      return res
  }
}
// 7
// 9
// 6

// 1 2 3 4
// right: column
// left: 0
// up: 0
// bottom: row