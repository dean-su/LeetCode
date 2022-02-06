#include<bits/stdc++.h>

class Twitter {
private:
    unordered_map<int, unordered_set<int>> friends;
    int timeStamp;
    priority_queue<array<int, 3>> timeLine;
public:
    Twitter() {
        friends.clear();
        timeStamp = 0;
        timeLine = priority_queue<array<int, 3>>();
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeLine.push({timeStamp++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<array<int, 3>> timeLines = timeLine;
        int n = 0;
        while (n<10 && !timeLines.empty()) {
            array<int, 3> topFeed = timeLines.top();
            if(topFeed[2] == userId || friends[userId].find(topFeed[2]) != friends[userId].end() ) {
                res.push_back(topFeed[1]);
                n++;
            }
            timeLines.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */