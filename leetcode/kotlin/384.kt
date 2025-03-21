class Solution(val nums: IntArray) {

  val initialNums = nums.copyOf()

  fun reset(): IntArray {
      return initialNums
  }

  fun shuffle(): IntArray {
      val target = nums.size-1
      for(target in nums.size-1 downTo 0) {
          val replace = Random.nextInt(0,target+1)
          val temp = nums[replace]
          nums[replace] = nums[target]
          nums[target] = temp
      }
      return nums
  }

}

/**
* Your Solution object will be instantiated and called as such:
* var obj = Solution(nums)
* var param_1 = obj.reset()
* var param_2 = obj.shuffle()
*/

// Fisher-Yates Algorithm
