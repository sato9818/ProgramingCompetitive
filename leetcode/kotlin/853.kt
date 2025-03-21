class Solution {
  data class Car(
      val position: Int,
      val speed: Int,
  )
  fun carFleet(target: Int, position: IntArray, speed: IntArray): Int {
      val cars = mutableListOf<Car>()
      val stack = mutableListOf<Double>()
      for(i in 0 until position.size) {
          cars.add(Car(position[i], speed[i]))
      }

      cars.sortWith(compareBy { it.position })

      for(car in cars) {
          val time = (target - car.position).toDouble() / car.speed
          while(stack.size != 0 && stack.last() <= time) {
              stack.removeLast()
          }
          stack.add(time)
      }
      return stack.size
  }
}

// 100
// 25, 48, 96
// 0 3 5 8 10
// 1 3 1 4 2
// 12 3 7 1 1
// 0 2 4
// 4 2 1
// 25 48 96
// 0 1   3
// 5 3   3
// 2 3  3.3
// Time: O(nlogn)
// Space: O(n)
