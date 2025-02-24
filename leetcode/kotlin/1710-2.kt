class Solution {
  fun maximumUnits(boxTypes: Array<IntArray>, truckSize: Int): Int {
      val buckets = MutableList<Int>(1001) {0}

      boxTypes.forEach { box ->
          val boxCount = box[0]
          val boxUnit = box[1]
          buckets[boxUnit] += boxCount
      }

      var truckRoom = truckSize
      var res = 0
      for(unit in 1000 downTo 1) {
          if(truckRoom == 0) {
              return res
          }
          val box = min(truckRoom, buckets[unit])
          res += box * unit
          truckRoom -= box
      }
      return res
  }
}
// Time: O(n)
// Space: O(max(unit))