class Solution {
  fun minEatingSpeed(piles: IntArray, h: Int): Int {
      var maxPile = 0
      piles.forEach {
          maxPile = max(maxPile, it)
      }
      var left = 1
      var right = maxPile

      while(left < right) {
          val k = (left + right) / 2
          if(canEat(k,piles,h)) {
              right = k
          } else {
              left = k + 1
          }
      }

      return right
  }

  private fun canEat(k: Int, piles: IntArray, h: Int): Boolean {
      var remain = h
      for(pile in piles) {
          val hours = pile / k + if(pile%k > 0) 1 else 0
          remain -= hours
          if(remain < 0) {
              return false
          }
      }
      return true
  }
}
/*
1 <= k <= max(piles)

Time: O(nlogm) m: the maximum num in piles
Space: O(1)
*/