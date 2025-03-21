class Solution {
  fun isHappy(n: Int): Boolean {
      var slow = next(n)
      var fast = next(next(n))
      while(fast != 1) {
          if(slow == fast) {
              return false
          }
          slow = next(slow)
          fast = next(next(fast))
      }

      return true
  }

  private fun next(n: Int): Int {
      var res = 0
      var cur = n
      while(cur != 0) {
          val remain = cur % 10
          res += remain * remain
          cur /= 10
      }
      return res
  } 
}