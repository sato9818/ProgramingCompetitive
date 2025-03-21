class Solution {
  fun dailyTemperatures(temperatures: IntArray): IntArray {
      val res = IntArray(temperatures.size)
      for(left in temperatures.size-2 downTo 0) {
          var right = left+1
          while(temperatures[left] >= temperatures[right]) {
              if(res[right] == 0) {
                  break
              }

              right += res[right]
          }
          if(temperatures[left] < temperatures[right]) {
              res[left] = right-left
          }
      }

      return res
  }
}

// Time: O(n)
// Space: O(1)
// [73,74,75,71,69,72,76,73]
// 　　　　　4 2  1　1　1　0
//         i
//                     j
// []