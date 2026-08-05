class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxproduct(n, 0);
        vector<int> minproduct(n, 0);

        maxproduct[0] = minproduct[0] = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {
            maxproduct[i] = max(nums[i], max(nums[i] * maxproduct[i-1], nums[i] * minproduct[i-1]));
            minproduct[i] = min(nums[i], min(nums[i] * maxproduct[i-1], nums[i] * minproduct[i-1]));
            result = max(result, maxproduct[i]);
        }

        return result;
    }
};

