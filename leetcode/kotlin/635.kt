// "2017:01:01:23:59:59"
// "Year:Month:Day:Hour:Minute:Second"
class LogSystem() {
    data class Log(
    	val id: Int,
        val timestamp: Timestamp,
    ) {
        data class Timestamp(
            private val year: String,
            private val month: String,
            private val day: String,
            private val hour: String,
            private val minute: String,
            private val second: String,
        ) {
            fun isInRange(start: Timestamp, end: Timestamp, granularity: String): Boolean {
                val yearInRange = start.year <= this.year && this.year <= end.year
             	val monthInRange = start.month <= this.month && this.month <= end.month && yearInRange
                val dayInRange = start.day <= this.day && this.day <= end.day && monthInRange
                val hourInRange = start.hour <= this.hour && this.hour <= end.hour && dayInRange
                val minuteInRange = start.minute <= this.minute && this.minute <= end.minute && yearInRange
                val secondInRange = start.second <= this.second && this.second <= end.second && minuteInRange
                
                return when(granularity) {
                    "Year" -> yearInRange
                    "Month" -> monthInRange
                    "Day" -> dayInRange
                    "Hour" -> hourInRange
                    "Minute" -> minuteInRange
                    "Second" -> secondInRange
                    else -> {
                        // throw exception
                        false
                    }
                }
            }
        }
    }
    
    val logStorage = mutableListOf<Log>()
    
    
    fun put(id: Int, timestamp: String) {
        val timestampString = timestamp.split(":")
        // if(timestampString.size != 6) {
        //     throw RuntimeException()
        // }
        logStorage.add(Log(id = id, timestamp = LogSystem.Log.Timestamp(timestampString[0], timestampString[1],timestampString[2], timestampString[3],timestampString[4], timestampString[5])))
    }
    
    fun retrieve(start: String, end: String, granularity: String): List<Int> {
        val startString = start.split(":")
        val endString = end.split(":")
        val startTimestamp = LogSystem.Log.Timestamp(startString[0], startString[1],startString[2], startString[3],startString[4], startString[5])
	    val endTimestamp = LogSystem.Log.Timestamp(endString[0], endString[1],endString[2], endString[3],endString[4], endString[5])
        
        val ids = mutableListOf<Int>()
        for(log in this.logStorage) {
          if(log.timestamp.isInRange(startTimestamp, endTimestamp, granularity)) {
              ids.add(log.id)
          }
        }
        
        return ids
    }
}

fun main() {
    val logSystem = LogSystem()
    logSystem.put(1, "2017:01:01:22:59:59") 
    logSystem.put(2, "2017:01:02:23:59:59")
    logSystem.put(3, "2017:02:01:23:59:59")
    
    logSystem.retrieve("2017:01:01:00:00:00", "2017:01:01:22:59:59", "Day").forEach {
        println(it)
    }
}