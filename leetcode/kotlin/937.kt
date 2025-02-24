class Solution {
  fun reorderLogFiles(logs: Array<String>): Array<String> {
      val modifiedLogs = logs.map { log ->
          log.split(" ", limit = 2)
      }

      val letterLogs = modifiedLogs.filter { log ->
          !log[1][0].isDigit()
      }

      val digitLogs = modifiedLogs.filter { log ->
          log[1][0].isDigit()
      }

      val sortedLetterLogs = letterLogs.toMutableList()
      sortedLetterLogs.sortWith(compareBy({it[1]}, {it[0]}))

      return (sortedLetterLogs + digitLogs).map {
          "${it[0]} ${it[1]}"
      }.toTypedArray()
  }
}

// O(n*k*logn)
// O(n)