class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;

        auto cmp = [](pair<char,int>& a, pair<char,int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);

        for(auto& p : freq) pq.push(p);

        string res;
        while(!pq.empty()) {
            auto [ch, f] = pq.top(); pq.pop();
            res.append(f, ch);
        }
        return res;
    }
};
