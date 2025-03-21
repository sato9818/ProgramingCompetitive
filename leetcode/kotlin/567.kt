class Solution {
  fun checkInclusion(s1: String, s2: String): Boolean {
      val baseCount = mutableMapOf<Char,Int>()
      for(ch in s1) {
          baseCount[ch] = baseCount.getOrDefault(ch, 0) + 1
      }
      var validCounter = 0
      val charCount = mutableMapOf<Char,Int>()
      var left = 0
      for(right in 0 until s2.length) {
          val ch = s2[right]
          if(ch in baseCount) {
              charCount[ch] = charCount.getOrDefault(ch, 0) + 1
              if(charCount[ch] == baseCount[ch]) {
                  validCounter++
                  if(validCounter == baseCount.size) {
                      return true
                  }
              }
              while(charCount[ch]!! > baseCount[ch]!!) {
                  val ch2 = s2[left]
                  if(charCount[ch2] == baseCount[ch2]) {
                      validCounter--
                  }
                  charCount[ch2] = charCount[ch2]!! - 1
                  left++
              }
          } else {
              charCount.clear()
              validCounter = 0
              left = right+1
          }
      }
      return false
  }
}

/*
a: 1
b: 2
validCounter: 2
s1 = "abb",

ooolleoooleh
R
L
Time: O(n)
Space: O(1) (s1 and s2 consist of lowercase English letters.)
*/