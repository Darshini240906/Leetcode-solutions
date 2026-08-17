class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], i, 0});
        }

        int val = 0;

        for (int count = 0; count < k; count++) {
            auto [v, r, c] = minHeap.top();
            minHeap.pop();

            val = v;

            if (c + 1 < n) {
                minHeap.push({matrix[r][c+1], r, c+1});
            }
        }

        return val;
    }
};
