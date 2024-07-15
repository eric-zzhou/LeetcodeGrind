# https://neetcode.io/problems/design-twitter-feed
# https://leetcode.com/problems/design-twitter/

from typing import List
from collections import defaultdict
import heapq


class Twitter:
    def __init__(self):
        self.count = 0
        self.tweetMap = defaultdict(list)  # userId -> list of [count, tweetIds]
        self.followMap = defaultdict(set)  # userId -> set of followeeId

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        minHeap = []

        self.followMap[userId].add(userId)
        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                index = len(self.tweetMap[followeeId]) - 1
                count, tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])

        while minHeap and len(res) < 10:
            count, tweetId, followeeId, index = heapq.heappop(minHeap)
            res.append(tweetId)
            if index >= 0:
                count, tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)


# Faster solution
class Twitter:

    def __init__(self):
        self.user_tweets = defaultdict(tuple)
        self.user_follows = defaultdict(set)
        self.tweet_time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId in self.user_tweets:
            self.user_tweets[userId].append((self.tweet_time, tweetId))
        else:
            self.user_follows[userId].add(userId)
            self.user_tweets[userId] = [(self.tweet_time, tweetId)]
        self.tweet_time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        total_tweets = 0
        ptr_list = []
        for followee in self.user_follows[userId]:
            ptr_list.append([followee, len(self.user_tweets[followee]) - 1])
            total_tweets += len(self.user_tweets[followee])

        feeds = []
        for i in range(min(total_tweets, 10)):
            recent_tweet_ptr = 0
            recent_time = 0
            for j in range(len(ptr_list)):
                if (
                    ptr_list[j][1] >= 0
                    and recent_time
                    <= self.user_tweets[ptr_list[j][0]][ptr_list[j][1]][0]
                ):
                    recent_time = self.user_tweets[ptr_list[j][0]][ptr_list[j][1]][0]
                    recent_tweet_ptr = j
            feeds.append(
                self.user_tweets[ptr_list[recent_tweet_ptr][0]][
                    ptr_list[recent_tweet_ptr][1]
                ][1]
            )
            ptr_list[recent_tweet_ptr][1] -= 1
        return feeds

    def follow(self, followerId: int, followeeId: int) -> None:
        self.user_follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.user_follows[followerId]:
            self.user_follows[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
