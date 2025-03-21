class Solution {
  data class PendingTask(
      val count: Int,
      val time: Int,
  )

  fun leastInterval(tasks: CharArray, n: Int): Int {
      var curTime = 0
      val count = mutableMapOf<Char, Int>()
      val maxHeap = PriorityQueue<Int>(compareByDescending{it})
      val deque = ArrayDeque<PendingTask>()
      for(task in tasks) {
          count[task] = count.getOrDefault(task, 0) + 1
      }

      for((k,v) in count) {
          maxHeap.add(v)
      }

      while(maxHeap.isNotEmpty()) {
          if(deque.isNotEmpty() && deque.first().time == curTime) {
              maxHeap.add(deque.first().count)
              deque.removeFirst()
          }
          val task = maxHeap.poll()
          if(task > 1){
              deque.addLast(PendingTask(task-1, curTime+n+1))
          }
          if(maxHeap.isEmpty() && deque.isNotEmpty()) {
              val pendingTask = deque.first()
              deque.removeFirst()
              curTime = pendingTask.time
              maxHeap.add(pendingTask.count)
          } else {
              curTime++
          }
      }
      return curTime
  }
}

// maxHeap: {1}    
// queue: 
// time: 7
// n: 2