class Solution {
  fun letterCombinations(digits: String): List<String> {
      val mapping = listOf("abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz")
      val substring = StringBuilder()
      val res = mutableListOf<String>()
      fun dfs(idx: Int) {
          if(idx == digits.length) {
              if(substring.length > 0) {
                  res.add(substring.toString())
              }
              return
          }
          val digit = digits[idx]
          for(ch in mapping[digit - '2']) {
              substring.append(ch)
              dfs(idx+1)
              substring.deleteAt(substring.length-1)
          }
      }

      dfs(0)
      return res
  }
}

// "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
// Time: O(n*4^n)
// Space: O(n)