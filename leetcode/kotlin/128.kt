class Solution {
  fun longestConsecutive(nums: IntArray): Int {
      val seq = mutableMapOf<Int,Int>()
      for(num in nums) {
          if(num in seq) {
              continue
          }
          if((num-1) in seq && (num+1) in seq) {
              val left = seq[num-1]!!
              val right = seq[num+1]!!

              seq[left] = right
              seq[right] = left
              seq[num] = num
          } else if((num+1) in seq) {
              val right = seq[num+1]!!
              seq[num] = right
              seq[right] = num
          } else if((num-1) in seq) {
              val left = seq[num-1]!!
              seq[num] = left
              seq[left] = num
          } else {
              seq[num] = num
          }
      }

      var res = 0
      for(num in nums) {
          res = max(abs(seq[num]!! - num) + 1, res)
      }

      return res
  }
}

// 1:4. 2:2  3:4 4:1
// hashmap: key is num and value should point to other side of index
// 1. currentNum + 1 is already existed
// 2. currentNum - 1 is already existed
// 3. currentNum + 1 and currentNum - 1 are already exsited
// 1 2 3 4 5
// hashmap[1] = 5
// hashmap[5] = 1
// 1.
// 2 3 4 5
// hashmap[2] = 5
// hashmap[5] = 2
// 3.
// 1 2 4 5
// hashmap[1] = 2
// hashmap[2] = 1
// hashamp[4] = 5
// hashmap[5] = 4
// 3
//  