class Solution {
  fun findDuplicate(nums: IntArray): Int {
      var slow = 0
      var fast = 0
      while(true) {
          slow = nums[slow]
          fast = nums[nums[fast]]
          if(slow == fast) {
              break
          }
      }

      var slow2 = 0

      while(slow2 != slow) {
          slow2 = nums[slow2]
          slow = nums[slow]
      }
      return slow
  }
}

/*
n=3
[1,3]
nums[1 2 3 3]
1,3,4,2,2
0 1 2 3 4
    ^
*/