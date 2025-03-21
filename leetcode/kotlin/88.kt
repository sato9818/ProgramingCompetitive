class Solution {
  fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
      var i = m-1
      var j = n-1
      while(i >= 0 && j >= 0) {
          if(nums1[i] > nums2[j]) {
              nums1[i+j+1] = nums1[i]
              i--
          } else {
              nums1[i+j+1] = nums2[j]
              j--
          }
      }

      while(j >= 0) {
          nums1[j] = nums2[j]
          j--
      }
  }
}

// [4,7,8,0,0,0], m = 3, nums2 = 
//        
// [3,5,6]
//  J 