class Solution {
  fun lastStoneWeight(stones: IntArray): Int {
      val weight = MutableList(1001) { 0 }
      for(stone in stones) {
          weight[stone]++
      }

      var first: Int? = null
      var second: Int? = null
      for(i in 1000 downTo 1) {
          for(j in 0 until weight[i]) {
              if(first == null) {
                  first = i
              } else if(second == null) {
                  second = i
              }

              if(first != null && second != null) {
                  val diff = first - second
                  if(diff != 0 && diff >= i) {
                      first = diff
                      second = null
                  } else {
                      weight[diff]++
                      first = null
                      second = null
                  }
              }
          }
      }

      if(first != null) {
          return first
      } else {
          return 0
      }
  }
}

// Time: O(n + w) w: max(stones)
// Space: O(w)