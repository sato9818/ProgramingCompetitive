class Solution {
  fun minimumOperations(nums: IntArray): Int {
      val uniqueNum = nums.toMutableSet()
      uniqueNum.remove(0)
      return uniqueNum.size
  }
}

// Return the number of unique value in nums. 
// Time: O(n) n: the number of nums
// Space: O(n)

// Time: O(nlogn)
// Space: O(1)
