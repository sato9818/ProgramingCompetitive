class Solution {
  fun insert(intervals: Array<IntArray>, newInterval: IntArray): Array<IntArray> {
      val newIntervals = mutableListOf<IntArray>()

      var newStart = newInterval[0]
      var newEnd = newInterval[1]
      var added = false
      intervals.forEach { interval ->
          if(added){
              newIntervals.add(interval)
          } else {
              if(newEnd < interval[0]) {
                  newIntervals.add(intArrayOf(newStart, newEnd))
                  newIntervals.add(interval)
                  added = true
              } else if(newStart > interval[1]) {
                  newIntervals.add(interval)
              } else {
                  newStart = min(newStart, interval[0])
                  newEnd = max(newEnd, interval[1])
              }
          }
      }
      if(!added) {
          newIntervals.add(intArrayOf(newStart, newEnd))
      }

      return newIntervals.toTypedArray()
  }
}
// [4,8]
// [1,2]
// [3,5], <- start:1
// [6,7],
// [8,10],
// [12,16] <- end:4

// [2,5]
// start: 2
// [1,3]
// [6,9]
//  3,9 -> 0
//  ^3
//  1,6 -> 1
//     ^6

// [6,7]
// 
// [1,2]
// [3,5]
// [9,10]
// 2,5,10 -> 2
//     ^7
// 1,3,9 -> 2
//     ^6
// 