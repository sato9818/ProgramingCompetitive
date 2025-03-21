class Solution {
  fun generateParenthesis(n: Int): List<String> {
      val stack = mutableListOf<Char>()
      val res = mutableListOf<String>()
      fun dfs(remain: Int, sum: Int) {
          if(remain == 0 && sum == 0) {
              res.add(stack.joinToString(""))
              return
          }
          if(sum < 0 || remain < 0) {
              return
          }
          stack.add('(')
          dfs(remain-1, sum+1)
          stack.removeLast()
          stack.add(')')
          dfs(remain, sum-1)
          stack.removeLast()
      }
      dfs(n, 0)
      return res
  }
}
// Time: O(2nCn + 2n*k) k: the number of valid answer, k < 2nCn
// Space: O(n) without output list
// 2nCn ~ 4^n / n^(3/2)