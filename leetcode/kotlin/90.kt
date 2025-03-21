class Solution {
  fun subsetsWithDup(nums: IntArray): List<List<Int>> {
      val res = mutableListOf<List<Int>>()
      val subset = mutableListOf<Int>()
      nums.sort()
      fun dfs(idx: Int) {
          res.add(subset.toList())
          for(i in idx until nums.size) {
              if(i > idx && nums[i] == nums[i-1]) continue
              subset.add(nums[i])
              dfs(i+1)
              subset.removeLast()
          }
      }

      dfs(0)
      return res
  }
}

// Time: O(2^n * n)
// Space: O(n)
