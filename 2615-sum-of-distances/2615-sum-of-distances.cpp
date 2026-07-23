class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n, 0);

        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto& [val, idxs] : mp) {
            int k = idxs.size();
            vector<long long> prefix(k+1, 0);

            for (int t = 0; t < k; t++) {
                prefix[t+1] = prefix[t] + idxs[t];
            }

            for (int t = 0; t < k; t++) {
                long long left = (long long)idxs[t] * t - prefix[t];
                long long right = (prefix[k] - prefix[t+1]) - (long long)idxs[t] * (k - t - 1);
                ans[idxs[t]] = left + right;
            }
        }
        return ans;
    }
};
