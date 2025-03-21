class Solution {
  fun findDuplicate(nums: IntArray): Int {
      var res = 0 
      for(i in 0 until 32) {
          var real = 0
          var ideal = 0
          val mask = 1 shl i

          for(num in nums) {
              if((num and mask) > 0) {
                  real++
              }
          }

          for(num in 1 until nums.size) {
              if((num and mask) > 0) {
                  ideal++
              }
          }

          if(real > ideal) {
              res = res or mask
          }
      }

      return res
  }
}

/*
n=3
[1,3]
nums[1 2 3 3]
1 2  3  4
1 10 11 100
3 3  3  3  3
11 11 11 11 11 

1,3,4,2,2
0 1 2 3 4
    ^
*/