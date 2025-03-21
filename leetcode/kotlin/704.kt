class Solution {
  fun search(nums: IntArray, target: Int): Int {
      var left = 0
      var right = nums.size-1

      while(left <= right) {
          val mid = left + right
          if(nums[mid] == target) {
              return mid
          } else if(nums[mid] > target) {
              right = mid-1
          } else {
              left = mid+1
          }
      }

      return -1
  }
}

// Time: O(logn)
// Space: O(1)