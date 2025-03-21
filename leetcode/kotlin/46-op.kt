class Solution {
  fun permute(nums: IntArray): List<List<Int>> {
      val res = mutableListOf<List<Int>>()
      fun dfs(idx: Int) {
          if(idx == nums.size) {
              res.add(nums.toList())
              return
          }
          for(i in idx until nums.size) {
              var tmp = nums[i]
              nums[i] = nums[idx]
              nums[idx] = tmp
              dfs(idx+1)
              tmp = nums[i]
              nums[i] = nums[idx]
              nums[idx] = tmp
          }
      }

      dfs(0)
      return res
  }
}

// Time: O(n! * n)
// space: O(n! * n)