// Amazon
class Solution {
  fun longestValidSubstring(word: String, forbidden: List<String>): Int {
      val n = word.length
      var left = n-1
      var right = n-1
      var maxLength = 0
      var substr = ""
      val forbiddenSet = forbidden.toSet()

      // substr is valid
      while(left > -1 && left <= right) {
          var substr = ""
          var isValid = true
          for(i in left..min(right, left+9)){
              substr += word[i]
              if(substr in forbiddenSet) {
                  isValid = false
                  right = i-1
                  break
              }
          }
          if(isValid) {
              maxLength = max(right - left + 1, maxLength)
          }
          left--
      }
      return maxLength
  }
}
// Time: O(N*M*M) M: the max length of forbidden word, N: word length
// Space: O(K*M) the size of forbidden list

// ["bbb","aacb","babbb","bcab"]
// "babbb"
//   L
//     R

// ["aaa","cb"]
// substr = c
// cbaaaabc
//        L   
//        R