class Solution {
  fun gcd(a: Int, b: Int): Int {
      if (b == 0) return a  
      else return gcd(b, a % b)  
  }

  fun maxScore(nums: IntArray): Int {
      val n = nums.size
      val dpSize = (1 shl n)
      val dp = MutableList(dpSize) {0}

      fun findMaxScore(currentChoice: Int, count: Int): Int {
          if(dp[currentChoice] != 0) {
              return dp[currentChoice]
          }

          var res = 0

          for(i in 0..n-1) {
              if(((1 shl i) and currentChoice) != 0) {
                  continue
              }
              for(j in i+1..n-1) {
                  if(((1 shl j) and currentChoice) != 0) {
                      continue
                  }
                  val nextChoice = currentChoice + (1 shl i) + (1 shl j)
                  res = max(res, findMaxScore(nextChoice, count + 1) + gcd(nums[i], nums[j]) * count)
              }
          }
          dp[currentChoice] = res
          return res
      }

      return findMaxScore(0,1)
  }
}
// Time: O(n^2 * 2^n * log(m))
// Space: O(2^n + n)
