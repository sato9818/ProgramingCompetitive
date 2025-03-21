class Solution {
  data class NumberFrequency(
      val frequency: Int,
      val num: Int,
  )
  fun topKFrequent(nums: IntArray, k: Int): IntArray {
      val counter = mutableMapOf<Int,Int>()
      val minHeap = PriorityQueue<NumberFrequency>(compareBy { it.frequency })

      for(num in nums) {
          counter[num] = counter.getOrDefault(num,0) + 1
      }

      for((num,frequency) in counter) {
          if(minHeap.size == k) {
              val head = minHeap.first()
              if(head.frequency < frequency) {
                  minHeap.poll()
                  minHeap.add(NumberFrequency(frequency, num))
              }
          } else {
              minHeap.add(NumberFrequency(frequency, num))
          }
      }

      val res = IntArray(k)
      var i = 0
      while(minHeap.isNotEmpty()) {
          res[i++] = minHeap.poll().num
      }

      return res
  }
}

// nums = [1,1,1,2,2,3], k = 2
//         i
// count[1] -> 3
// count[2] -> 2
// count[3] -> 1
// minHeap: (2,2)(3,1)
// 1. count the each interger
// 2.1 Put each freq and number into minHeap
// 2.2 If there are k elements in minHeap, see head value. If curr is larger than head value, pop the head and put the current values
