class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Record answer once the first window is complete
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};