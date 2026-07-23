class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the maximum possible OR
        int maxOR = 0;
        for (int x : nums)
            maxOR |= x;

        int count = 0;

        // Step 2: Enumerate all subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int currOR = 0;

            // Build the subset represented by 'mask'
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    currOR |= nums[i];
            }

            if (currOR == maxOR)
                count++;
        }

        return count;
    }
};