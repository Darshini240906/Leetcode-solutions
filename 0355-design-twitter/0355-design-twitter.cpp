class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // max-heap by timestamp

        // include own tweets
        for (auto &t : tweets[userId]) pq.push(t);

        // include followees' tweets
        for (int followee : follows[userId]) {
            for (auto &t : tweets[followee]) pq.push(t);
        }

        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
