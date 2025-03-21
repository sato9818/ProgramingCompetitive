class Solution {
  fun trap(height: IntArray): Int {
      val leftMax = MutableList(height.size) { 0 }
      val rightMax = MutableList(height.size) { 0 }

      for(i in 0..height.size-2) {
          leftMax[i+1] = max(leftMax[i], height[i])
          rightMax[height.size-i-2] = max(rightMax[height.size-i-1], height[height.size-i-1])
      }
      var res = 0

      for(i in 0..height.size-1) {
          res += max(min(leftMax[i], rightMax[i]) - height[i],0)
      }
      return res
  }
}

//    [0,1,0,2,1,0,1,3,2,1,2,1]
//MaxL 0 0 1 1 2 2 2 2 3 3 3 3     R
//MaXR 3 3 3 3 3 3 3 2 2 2 1 0
//     0 0 1 1 2 2 2 2 2 2 1 0
//.    0 0 1 0 1 2 1 0 0 1 0 0

// Time: O(n)
// space: O(n)
