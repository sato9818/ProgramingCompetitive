class KthLargest(val k: Int, nums: IntArray) {
  // O(k)
  val minHeap = PriorityQueue<Int>()

 // Time: O(n) n: number of nums
  init {
      for(num in nums) {
          minHeap.add(num)
          if(minHeap.size > k) {
              minHeap.poll()
          }
      }
  }

  // Time: O(n) n: number of nums
  fun add(`val`: Int): Int {
      minHeap.add(`val`)
      if(minHeap.size > k) {
          minHeap.poll()
      }
      return minHeap.first()
  }
}

/**
* Your KthLargest object will be instantiated and called as such:
* var obj = KthLargest(k, nums)
* var param_1 = obj.add(`val`)
*/

// Time: O(nlogk)
// Space: O(k)