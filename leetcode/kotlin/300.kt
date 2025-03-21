class Solution {
  // fun lengthOfLIS(nums: IntArray): Int {
  //     val dp = MutableList(nums.size) { 0 }
  //     var res = 0
  //     (0..nums.size-1).forEach { i ->
  //         val num = nums[i]
  //         dp[i] = 1
  //         (0..i-1).forEach { j ->
  //             if(nums[j] < num) {
  //                 dp[i] = max(dp[i], dp[j] + 1)
  //             }
  //         }
  //         res = max(dp[i], res)
  //     }

  //     return res
  // }

  fun lengthOfLIS(nums: IntArray): Int {
      // DP: current possible LIS
      val dp = mutableListOf<Int>()
      dp.add(nums[0])
      (0..nums.size-1).forEach { i ->
          val num = nums[i]
          if(dp.last() < num) {
              dp.add(num)
          } else {
              val idx = dp.binarySearch(num).let {
                  if(it < 0) {
                      -(it+1)
                  } else {
                      it
                  }
              }
              dp[idx] = num
          }
      }

      return dp.size
  }
}

// dp[nums.size]: dp[i]: the LIS in subarr from 0 to i
// dp[i] = max(dp[j]+1, 1) if(nums[j] < nums[i]) 0 <= j <= i-1
// 0,1,0,3,2,3
// 0,1