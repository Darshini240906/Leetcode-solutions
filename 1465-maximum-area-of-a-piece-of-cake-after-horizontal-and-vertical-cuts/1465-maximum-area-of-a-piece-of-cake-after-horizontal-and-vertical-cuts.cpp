class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const long long MOD = 1000000007;

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxH = horizontalCuts[0];

        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, 1LL * (horizontalCuts[i] - horizontalCuts[i - 1]));
        }

        maxH = max(maxH, 1LL * (h - horizontalCuts.back()));

        long long maxV = verticalCuts[0];

        for (int i = 1; i < verticalCuts.size(); i++) {
            maxV = max(maxV, 1LL * (verticalCuts[i] - verticalCuts[i - 1]));
        }

        maxV = max(maxV, 1LL * (w - verticalCuts.back()));

        return (maxH * maxV) % MOD;
    }
};