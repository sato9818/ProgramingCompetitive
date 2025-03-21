class Solution {
  fun subsetsWithDup(nums: IntArray): List<List<Int>> {
      val res = mutableListOf<List<Int>>()
      nums.sort()
      var size = 0
      res.add(listOf<Int>())
      for(i in nums.indices) {
          val rangefirst = if(i > 0 && nums[i] == nums[i-1]) {
              size
          } else {
              0
          }
          size = res.size
          for(j in rangefirst until size) {
              val subset = res[j].toMutableList()
              subset.add(nums[i])
              res.add(subset)
          }
      }
      return res
  }
}

/*
0
[]
^
prev = 0

1
0..0
size = 1
1 2 2 3
^
[] [1]


2
0..1
size = 2
1 2 2 3
^
[] [1] [2] [1,2]

3
2..3
size = 4
1 2 2 3
  ^
[] [1] [2] [1,2] [2,2] [1,2,2]

4
0..res.size-1
1 2 2 3
    ^
[] [1] [2] [1,2] [2,2] [1,2,2] [3] [1,3] [2,3] [1,2,3] [2,2,3] [1,2,2,3]
*/

// Time: O(2^n * n)
// Space: O(1)

