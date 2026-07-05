class Twitter {
    int time;
    map<int,deque<pair<int,int>>> tweets;
    map<int,set<int>> followees;

public:
    Twitter() {
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({time++,tweetId});
        if (tweets[userId].size() > 10) tweets[userId].pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; vector<int> res;
        followees[userId].insert(userId);
        for (auto followee : followees[userId]) for (auto tweet : tweets[followee]) pq.push(tweet);
        while (!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res.size() > 10 ? vector<int>(res.begin(),res.begin()+10) : res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
