class Solution {
  fun lastStoneWeight(stones: IntArray): Int {
      val maxHeap = PriorityQueue<Int>(compareByDescending{it})
      for(stone in stones) {
          maxHeap.add(stone)
      }

      while(maxHeap.size > 1) {
          val y = maxHeap.poll()
          val x = maxHeap.poll()

          if(y-x > 0) {
              maxHeap.add(y-x)
          }
      }

      if(maxHeap.size == 0) {
          return 0
      } else{
          return maxHeap.first()
      }
  }
}