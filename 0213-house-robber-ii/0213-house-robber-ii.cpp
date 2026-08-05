class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[start];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int caseA = robLinear(nums, 0, n-2);

        int caseB = robLinear(nums, 1, n-1);

        return max(caseA, caseB);
    }
};
