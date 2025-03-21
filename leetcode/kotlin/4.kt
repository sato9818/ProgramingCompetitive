class Solution {
  fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
      val (main, sub) = if(nums1.size < nums2.size) {
          nums1 to nums2
      } else {
          nums2 to nums1
      }

      val half = (nums1.size + nums2.size) / 2
      
      var left = -1
      var right = main.size-1
      while(left <= right) {
          val mid = (left + right) / 2
          val subIdx = half - (mid+1) - 1
          val mainRight = if(mid + 1 < main.size) main[mid+1] else Int.MAX_VALUE
          val mainLeft = if(mid >= 0) main[mid] else Int.MIN_VALUE
          val subRight = if(subIdx + 1 < sub.size) sub[subIdx+1] else Int.MAX_VALUE
          val subLeft = if(subIdx >= 0) sub[subIdx] else Int.MIN_VALUE

          if(subLeft <= mainRight && subRight >= mainLeft) {
              if((nums1.size + nums2.size) % 2 == 0) {
                  return (max(subLeft, mainLeft) + min(mainRight, subRight)).toDouble() / 2
              } else{
                  return min(mainRight, subRight).toDouble()
              }
          }

          if(subRight < mainLeft) {
              right = mid - 1
              continue
          }

          if(subLeft > mainRight) {
              left = mid + 1
              continue
          }
      }
      return -1.0
  }
}

/*
O(log(min(m,n)))
O(1)

1
m
*/