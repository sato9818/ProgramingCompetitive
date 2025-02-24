class Twitter() {
  val followees = mutableMapOf<Int, MutableSet<Int>>()
  val tweets = mutableMapOf<Int, MutableList<Pair<Int,Int>>>()
  var count = 0

  fun postTweet(userId: Int, tweetId: Int) {
      tweets[userId] = tweets.getOrDefault(userId, mutableListOf<Pair<Int,Int>>())
      tweets[userId]!!.add(count to tweetId)
      count++    
  }

  data class FeedTweet(
      val count: Int,
      val tweetId: Int,
      val userId: Int,
      val listIndex: Int
  )

  fun getNewsFeed(userId: Int): List<Int> {
      val res = mutableListOf<Int>()
      val feedsCand = PriorityQueue<FeedTweet>(compareByDescending {it.count})

      followees[userId] = followees.getOrDefault(userId, mutableSetOf<Int>())
      if(userId !in followees[userId]!!) {
          followees[userId]!!.add(userId)
      }
      val followeeIds = followees[userId] ?: emptySet()

      if(followeeIds.size >= 10) {
          val mostRecentTenTweets = PriorityQueue<FeedTweet>(compareBy { it.count })
          for(followeeId in followeeIds) {
              val followeeTweets = tweets[followeeId] ?: continue
              val recentTweet = followeeTweets.last()
              mostRecentTenTweets.add(FeedTweet(recentTweet.first, recentTweet.second, followeeId, followeeTweets.size-1))

              if(mostRecentTenTweets.size > 10) {
                  mostRecentTenTweets.poll()
              }
          }

          while(mostRecentTenTweets.isNotEmpty()) {
              feedsCand.add(mostRecentTenTweets.poll())
          }
      } else {
          for(followeeId in followeeIds) {
              val followeeTweets = tweets[followeeId] ?: continue
              val recentTweet = followeeTweets.last()
              feedsCand.add(FeedTweet(recentTweet.first, recentTweet.second, followeeId, followeeTweets.size-1))
          }
      }

      
      while(feedsCand.isNotEmpty() && res.size < 10) {
          val tweet = feedsCand.poll()
          res.add(tweet.tweetId)

          if(tweet.listIndex - 1 >= 0) {
              val newTweet = tweets[tweet.userId]!![tweet.listIndex-1]
              feedsCand.add(FeedTweet(newTweet.first, newTweet.second, tweet.userId, tweet.listIndex-1))
          }
      }

      return res
  }

  fun follow(followerId: Int, followeeId: Int) {
      followees[followerId] = followees.getOrDefault(followerId, mutableSetOf<Int>())
      followees[followerId]!!.add(followeeId)
  }

  fun unfollow(followerId: Int, followeeId: Int) {
      followees[followerId]?.remove(followeeId)
  }
}

/**
* Your Twitter object will be instantiated and called as such:
* var obj = Twitter()
* obj.postTweet(userId,tweetId)
* var param_2 = obj.getNewsFeed(userId)
* obj.follow(followerId,followeeId)
* obj.unfollow(followerId,followeeId)
*/

// feeds: userId -> feedTweetIds
// feedTweetsIds: sortedSet sorted by tweet id in desceding order. Includes my tweets and followers tweets.
// tweets: userId -> tweetIds limit: 10
// tweetIds: this set includes my tweets
// followees: map userId -> userIds(set), users in values follows userId
//
// O(nlogn) n: the number of followees
// postTweet() -> put the tweet into tweets, and followee's feeds.
// O(logm) m: the number of feeds
// getNewsFeed() -> get 10 feeds from feeds
// O(logn) m: the number of followeeId's feeds
// follow() -> followees[followerId].add(followeeId), then put follower's (at most 10) tweets into followeeId's feeds
// O(logn)
// unfollow() -> followees[followerId].remove(followeeId) then delete follower's tweets from followeeId's feeds