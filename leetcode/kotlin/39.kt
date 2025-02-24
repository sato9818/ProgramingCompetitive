class Solution {
  fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
      val n = candidates.size
      val ans = mutableListOf<List<Int>>()

      candidates.sort()
      
      fun findCombination(sum: Int, currentList: MutableList<Int>, currentIndex: Int) {
          if(sum > target) {
              return 
          }
          if(sum == target) {
              ans.add(currentList.toList())
              return 
          }
          for(i in currentIndex..n-1) {
              currentList.add(candidates[i])
              findCombination(sum + candidates[i], currentList, i)
              currentList.removeLast()
          }
      }
      
      findCombination(0, mutableListOf<Int>(), 0)

      return ans
  }
}

// Time: O(n^(t/m)) t: target, m: minimum value in candidates
// Space: O(t/m + c) c: all number in ans