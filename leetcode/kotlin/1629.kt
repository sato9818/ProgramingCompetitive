class Solution {
  fun slowestKey(releaseTimes: IntArray, keysPressed: String): Char {
      var lastSecond = 0
      var maxDuration = 0
      var ans = 'a'
      for(i in 0..releaseTimes.size-1) {
          val duration = releaseTimes[i] - lastSecond
          lastSecond = releaseTimes[i]
          if(duration > maxDuration) {
              ans = keysPressed[i]
              maxDuration = duration
          } else if(duration == maxDuration && keysPressed[i].toInt() > ans.toInt()) {
              ans = keysPressed[i]
              maxDuration = duration
          }
      }

      return ans
  }
}

// Time: O(n)
// Space: O(1)