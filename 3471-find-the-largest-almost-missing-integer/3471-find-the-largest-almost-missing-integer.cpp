class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> mp;

        // Generate all subarrays of size k
        for (int i = 0; i + k <= n; i++) {
            for (int j = i; j < i + k; j++) {
                mp[nums[j]].insert(i); // record subarray index
            }
        }

        int ans = -1;
        for (auto &p : mp) {
            if (p.second.size() == 1) { // appears in exactly one subarray
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};
