class Solution {
  fun maximumUnits(boxTypes: Array<IntArray>, truckSize: Int): Int {
      boxTypes.sortWith(compareByDescending { it[1] })

      var truckRoom = truckSize
      var res = 0
      for(i in 0..boxTypes.size-1) {
          if(truckRoom == 0) {
              return res
          }
          val box = min(truckRoom, boxTypes[i][0])
          res += box * boxTypes[i][1]
          truckRoom -= box
      }
      return res
  }
}
// Time: O(nlogn)
// Space: O(1)