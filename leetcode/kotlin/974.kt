class Solution {
  fun subarraysDivByK(nums: IntArray, k: Int): Int {
      val reminderCount = mutableMapOf<Int,Int>()
      var cumulative = 0
      var res = 0
      reminderCount[0] = 1
      for(num in nums) {
          cumulative = ((cumulative + num) % k + k) % k
          res += reminderCount.getOrDefault(cumulative, 0)
          reminderCount[cumulative] = reminderCount.getOrDefault(cumulative, 0) + 1
      }

      return res
  }
}

// 4,5,0,-2,-3,1
// sum reminder: 0
// cumulative reminder prefix: 0 4 4 4 2 4
// suffix:                       1 1 1 3 1 0
// time: O(n)
// space: O(k)
// KeyPoint: cumulativeSum[j] - cumulativeSum[i-1]
// もし A≡B(modk) ならば A−B≡0(modk) であることを利用する