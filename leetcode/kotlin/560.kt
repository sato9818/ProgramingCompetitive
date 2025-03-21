class Solution {
  fun subarraySum(nums: IntArray, k: Int): Int {
      var sum = 0
      var count = 0
      val prefix = mutableMapOf<Int,Int>()
      prefix[0] = 1
      for(right in nums.indices) {
          sum += nums[right]
          if(sum - k in prefix) {
              count += prefix[sum-k]!!
          }
          prefix[sum] = prefix.getOrDefault(sum, 0) + 1
      }
      return count
  }
}

// prefix sum: 1 2 7 8  6 7 8
//             1 1 5 1 -2 1 1
// -1                   1 1 
// 1: 1
// 2: 1
// 7: 2
// 8: 1
// 6: 1