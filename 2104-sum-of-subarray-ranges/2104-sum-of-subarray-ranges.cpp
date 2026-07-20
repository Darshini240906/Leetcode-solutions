class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> prevSmaller(n), nextSmaller(n);
        vector<int> prevGreater(n), nextGreater(n);

        stack<int> st;

        // ---------------- Previous Smaller ----------------
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ---------------- Next Smaller ----------------
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ---------------- Previous Greater ----------------
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ---------------- Next Greater ----------------
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long minCount =
                1LL * (i - prevSmaller[i]) * (nextSmaller[i] - i);

            long long maxCount =
                1LL * (i - prevGreater[i]) * (nextGreater[i] - i);

            ans += 1LL * nums[i] * (maxCount - minCount);
        }

        return ans;
    }
};