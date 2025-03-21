class MinStack() {
  val stack = mutableListOf<Long>()
  var minVal = Int.MAX_VALUE

  // 1. Push to stack
  // 2. If the val is smaller or equal to minStack head, then push it to minStask
  fun push(`val`: Int) {
      val longVal = `val`.toLong()
      if(stack.size == 0) {
          stack.add(0)
          minVal = `val`
      } else {
          stack.add(longVal - minVal.toLong())
          minVal = min(minVal, `val`)
      }
  }

  // 1. pop from stack
  // 2. If the poped value is the head of minStack, pop from minStack
  fun pop() {
      val poped = stack.last()
      stack.removeLast()

      if(poped < 0) {
          minVal = (minVal.toLong() - poped).toInt()
      }
  }

  // 1. Get the head of stack
  fun top(): Int {
      if(stack.last() < 0) {
          return minVal
      }
      return (stack.last() + minVal.toLong()).toInt()
  }

  // 1. Get the head of minStack
  fun getMin(): Int {
      return minVal
  }

}

/**
* Your MinStack object will be instantiated and called as such:
* var obj = MinStack()
* obj.push(`val`)
* var param_3 = obj.top()
* obj.pop()
* var param_4 = obj.getMin()
*/

/*
stack: the diff between min and the actual value. (actual - min)

3 1 2 4
stack: 0 -2 1 3 
min: 1
*/