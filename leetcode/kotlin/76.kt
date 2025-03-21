class Solution {
  fun minWindow(s: String, t: String): String {
      var left = 0
      var right = 0
      var satisfiedCharCount = 0
      val conditionMap = mutableMapOf<Char, Int>()
      val charCount = mutableMapOf<Char, Int>()

      var minLength = Int.MAX_VALUE
      var minLeft = -1

      t.forEach { ch ->
          conditionMap[ch] = conditionMap.getOrDefault(ch, 0) + 1
      }

      val uniqueCharCount = conditionMap.size

      s.forEachIndexed { right, ch ->
          charCount[ch] = charCount.getOrDefault(ch, 0) + 1
          if(conditionMap.containsKey(ch) && charCount[ch] == conditionMap[ch]) {
              satisfiedCharCount++
          }

          while(satisfiedCharCount == uniqueCharCount) {
              if(conditionMap.containsKey(s[left]) && charCount[s[left]] == conditionMap[s[left]]) {
                  satisfiedCharCount--
              }
              if(minLength > right - left+1) {
                  minLength = right - left+1
                  minLeft = left
              }
              charCount[s[left]] = charCount[s[left]]!! - 1
              left++
          }
      }

      if(minLeft == -1) {
          return ""
      }
      return s.slice(minLeft..minLeft+minLength -1)
  }
}

// ADOBECODEBANC
// ADOBEC
// ABC
// right: 5,left:0
// satisfiedCharCount: 3
// conditonMap: A:1, B:1, C:1
// hashMap: A:1, B:1, C:1 ...
// 1. increment left until the condtion is satisfied
// 2. Once the econdition is satisfied, increment right until the condtion is not satisfied
// On each step of 2, maintain the min length of the window and the string.
// O(t.len) m: the length of the window
// 