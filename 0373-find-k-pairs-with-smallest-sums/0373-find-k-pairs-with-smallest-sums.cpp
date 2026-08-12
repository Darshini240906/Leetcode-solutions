class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // min-heap: {sum, i, j}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});

        set<pair<int,int>> visited;
        visited.insert({0,0});

        while (!pq.empty() && result.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});

            // push next pair (i+1, j)
            if (i + 1 < nums1.size() && !visited.count({i+1, j})) {
                pq.push({nums1[i+1] + nums2[j], i+1, j});
                visited.insert({i+1, j});
            }

            // push next pair (i, j+1)
            if (j + 1 < nums2.size() && !visited.count({i, j+1})) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            }
        }

        return result;
    }
};
