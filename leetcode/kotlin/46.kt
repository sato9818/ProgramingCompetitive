class Solution {
  fun permute(nums: IntArray): List<List<Int>> {
      val used = MutableList<Boolean>(nums.size) {false}
      val subset = mutableListOf<Int>()

      val res = mutableListOf<List<Int>>()
      fun dfs() {
          if(subset.size == nums.size) {
              res.add(subset.toList())
              return
          }
          for((i, num) in nums.withIndex()) {
              if(used[i]) {
                  continue
              }
              used[i] = true
              subset.add(num)
              dfs()
              subset.removeLast()
              used[i] = false
          }
      }

      dfs()
      return res
  }
}

// Time: O(n! * n)
// space: O(n! * n)