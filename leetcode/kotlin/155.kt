class MinStack() {
  val stack = mutableListOf<Int>()
  val minStack = mutableListOf<Int>()

  // 1. Push to stack
  // 2. If the val is smaller or equal to minStack head, then push it to minStask
  fun push(`val`: Int) {
      stack.add(`val`)
      if(minStack.size == 0) {
          minStack.add(`val`)
          return
      }
      val head = minStack.last()
      if(`val` <= head) {
          minStack.add(`val`)
      }
  }

  // 1. pop from stack
  // 2. If the poped value is the head of minStack, pop from minStack
  fun pop() {
      val poped = stack.last()
      stack.removeLast()

      if(poped == minStack.last()) {
          minStack.removeLast()
      }
  }

  // 1. Get the head of stack
  fun top(): Int {
      return stack.last()
  }

  // 1. Get the head of minStack
  fun getMin(): Int {
      return minStack.last()
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
minStack: maintains the potential minValue

3 1 2 4
minStack:    3 1 
stack: 3 1 2 4 
*/