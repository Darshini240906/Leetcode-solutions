class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
            if (a.first == b.first) 
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for (string &word : words) 
            mp[word]++;

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
        for (auto &it : mp) 
            pq.push({it.second, it.first});

        vector<string> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
