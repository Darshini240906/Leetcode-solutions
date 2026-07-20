class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                int width = right - left - 1;
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};