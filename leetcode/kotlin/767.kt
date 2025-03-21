class Solution {
  fun reorganizeString(s: String): String {
      val count = MutableList(26) {0}
      val maxFrequency = PriorityQueue<Pair<Int,Char>>(compareByDescending{it.first})
      for(ch in s) {
          count[ch - 'a']++
      }
      
      for(i in 0..25) {
          if(count[i] == 0) continue
          maxFrequency.add(count[i] to ('a'+i))
      }

      var res = ""
      var prev = 'A'
      while(maxFrequency.isNotEmpty()) {
          val frequency = maxFrequency.poll()
          val count = frequency.first
          val ch = frequency.second
          if(prev == ch) {
              if(maxFrequency.isEmpty()) {
                  return ""
              } 
              val nextFrequency = maxFrequency.poll()
              res += nextFrequency.second
              if(nextFrequency.first > 1) {
                  maxFrequency.add(nextFrequency.first-1 to nextFrequency.second)
              }
              prev = nextFrequency.second
              maxFrequency.add(frequency)
          } else {
              res += ch
              if(count > 1) {
                  maxFrequency.add(count-1 to ch)
              }
              prev = ch
          }
      }

      return res
  }
}

// Time: O(nlogk) n: the length of s, k: the number of unique character
// Space: O(k)