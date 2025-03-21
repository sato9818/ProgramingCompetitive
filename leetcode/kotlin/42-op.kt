class Solution {
    fun trap(height: IntArray): Int {
        var left = 0
        var right = height.size-1
        var leftMax = 0
        var rightMax = 0
        var res = 0

        while(left < right) {
            if(leftMax < rightMax) {
                res += max(min(leftMax, rightMax) - height[left],0)
                leftMax = max(leftMax, height[left])
                left++
            } else {
                res += max(min(leftMax, rightMax) - height[right],0)
                rightMax = max(rightMax, height[right])
                right--
            }
        }

        return res + max(min(leftMax, rightMax) - height[right],0)
    }
}

//    [0,1,0,2,1,0,1,3,2,1,2,1]
//MaxL 0 0 1 1 2 2 2 2 3 3 3 3     R
//MaXR 3 3 3 3 3 3 3 2 2 2 1 0
//     0 0 1 1 2 2 2 2 2 2 1 0
//.    0 0 1 0 1 2 1 0 0 1 0 0

// [2,1,0,2]
//    L
//      R
// rM: 2, lM: 2
// Time: O(n)
// space: O(1)