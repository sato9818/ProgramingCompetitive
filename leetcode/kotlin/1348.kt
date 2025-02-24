// 同じツイートが少ないかつ検索のクエリ広い時はこっちの方が良い
// class TweetCounts() {
//     val tweetTimes = mutableMapOf<String, MutableList<Int>>()

//     fun recordTweet(tweetName: String, time: Int) {
//         tweetTimes[tweetName] = tweetTimes.getOrDefault(tweetName, mutableListOf())
//         tweetTimes[tweetName]!!.add(time)
//     }

//     fun getTweetCountsPerFrequency(freq: String, tweetName: String, startTime: Int, endTime: Int): List<Int> {
//         val unit = when(freq) {
//             "minute" -> 60
//             "hour" -> 3600
//             "day" -> 86400
//             else -> throw RuntimeException()
//         }
//         val times = tweetTimes[tweetName]!!
//         // [60, 118] -> [60, 118]
//         val listSize = (endTime - startTime)/unit + 1
//         val res = MutableList<Int>(listSize) { 0 }
//         for(t in times) {
//             if(t <= endTime && t >= startTime) {
//                 val index = (t-startTime)/unit
//                 res[index] = res[index]!! + 1
//             }
//         }

//         return res
//     }
// }

// 同じツイートが多いかつ検索のクエリが狭い時はこっちの方が良い
// O(ML*k + t) k: the kind of tweets, ML: max length of tweet, t: total number of unique tweet time
class TweetCounts() {
  val tweetTimes = mutableMapOf<String, SortedMap<Int, Int>>()

  // O(n/2)
  fun recordTweet(tweetName: String, time: Int) {
      tweetTimes[tweetName] = tweetTimes.getOrDefault(tweetName, sortedMapOf<Int,Int>())
      tweetTimes[tweetName]!![time] = tweetTimes[tweetName]!!.getOrDefault(time, 0) + 1
  }

  // Time: O(n + m) n: the number of unique time when the specific tweet is done, m: the length of the tweet
  fun getTweetCountsPerFrequency(freq: String, tweetName: String, startTime: Int, endTime: Int): List<Int> {
      val unit = when(freq) {
          "minute" -> 60
          "hour" -> 3600
          "day" -> 86400
          else -> throw RuntimeException()
      }
      // O(m)
      val times = tweetTimes[tweetName]!!.subMap(startTime, endTime+1)
      val listSize = (endTime - startTime)/unit + 1
      val res = MutableList<Int>(listSize) { 0 }
      // O(nlogn) in worst case
      for((t,count) in times) {
          if(t <= endTime && t >= startTime) {
              val index = (t-startTime)/unit
              res[index] = res[index]!! + count
          }
      }

      return res
  }
}

/**
* Your TweetCounts object will be instantiated and called as such:
* var obj = TweetCounts()
* obj.recordTweet(tweetName,time)
* var param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
*/

// tweetTimes = {tweet: listOf(times)}
// tweetTimes['tweet3'] = [0, 60, 10]
// 83181 83184
// Time: O(n/60) = O(n), Space: O(n/60) = O(n) n: endTime - startTime
// How to split [startTime, endTime] into time chunks
// [100, 119], [120, 179], [180, 200] [60 -> 119] [120]
// [startTime, 60*i-1][60*(i), 60*(i+1)-1][60*(i+1), endTime]
// i = (startTime + 1)/60
// endtime <= 60*n
// i >= endtime/60

// O(n + m) n: the tweets count of the specified tweet, m: the length of the tweet
// O(m * t + l) t: the kind of tweets, l: total number of tweets
// [119, 200] -> [100, 159], [160, 200]
// list of time: [0,110,120,190]
//               [nl,  1,  2,  3]
// 100 / 60 = 1: base index
// 0 -> [110]
// 1 -> [120]
// 2 -> [190]
// [startTime, startTime+59], [startTime+(i*unit), startTime+(i+1)*unit-1]
// startTime+(i*unit) <= time <= startTime+(i+1)*unit-1
// i*unit