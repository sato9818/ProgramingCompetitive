class Solution {
  fun evalRPN(tokens: Array<String>): Int {
      val stack = mutableListOf<Int>()

      for(token in tokens) {
          if(token.toIntOrNull() != null) {
              stack.add(token.toInt())
          } else {
              val b = stack.last()
              stack.removeLast()
              val a = stack.last()
              stack.removeLast()
              val res = when(token) {
                  "+" -> a+b
                  "-" -> a-b
                  "*" -> a*b
                  "/" -> a/b
                  else -> throw RuntimeException()
              }
              stack.add(res)
          }
      }
      return stack.last()
  }
}