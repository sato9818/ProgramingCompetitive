class Solution {
  fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
      val deque = ArrayDeque<Int>()

      for(i in 0 until k) {
          val num = nums[i]
          while(deque.size != 0 && deque.last() < num) {
              deque.removeLast()
          }
          deque.addLast(num)
      }

      val res = IntArray(nums.size - k + 1)
      res[0] = deque.first()
      for(i in k until nums.size) {
          val num = nums[i]
          val removedNum = nums[i-k]
          if(removedNum == deque.first()) {
              deque.removeFirst()
          }

          while(deque.size != 0 && deque.last() < num) {
              deque.removeLast()
          }
          deque.addLast(num)
          res[i-k+1] = deque.first()
      }
      return res
  }
}

/*
8679
313
deque: has potentail maximum values
time: O(n)
space:
  deque: O(k)
  res: O(n)
*/