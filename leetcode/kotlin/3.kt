class Solution {
  fun lengthOfLongestSubstring(s: String): Int {
      var left = 0
      val letter = mutableMapOf<Char, Int>()
      var res = 0
      for(right in 0..s.length-1) {
          val newLetter = s[right]
          letter[newLetter] = letter.getOrDefault(newLetter, 0) + 1
          while(left < right && letter.getOrDefault(newLetter, 0) > 1) {
              letter[s[left]] = letter.getOrDefault(s[left], 0) - 1
              if(letter[s[left]] == 0) {
                  letter.remove(s[left])
              }
              left++
          }
          res = max(right - left + 1, res)
      }

      return res
  }
}

// Time: O(n) n: the length of s
// Sapce: O(k) k: the number of unique char
// Can optimize while loop to use index of each char