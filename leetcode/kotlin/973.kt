class Solution {
  fun kClosest(points: Array<IntArray>, k: Int): Array<IntArray> {
      var left = 0
      var right = points.size-1

      while(left < right) {
          val pivot = distance(points[right])

          var i = left
          for(j in left until right) {
              if(distance(points[j]) < pivot) {
                  val tmp = points[i]
                  points[i] = points[j]
                  points[j] = tmp
                  i++
              }
          }
          val tmp = points[i]
          points[i] = points[right]
          points[right] = tmp

          if(i == k-1) {
              break
          } else if(i > k-1) {
              right = i-1
          } else {
              left = i+1
          }
      }

      return points.copyOfRange(0, k)
  }

  private fun distance(point: IntArray): Int {
      return point[0] * point[0] + point[1] * point[1]
  }
}