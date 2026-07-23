class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> leftProfit(n,0);
        vector<int> rightProfit(n,0);

        // Best profit from left
        int minPrice = prices[0];
        int profit = 0;

        for(int i = 0; i < n; i++)
        {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
            leftProfit[i] = profit;
        }

        // Best profit from right
        int maxPrice = prices[n-1];
        profit = 0;

        for(int i = n-1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            profit = max(profit, maxPrice - prices[i]);
            rightProfit[i] = profit;
        }

        // Try every split
        int ans = leftProfit[n-1];

        for(int i = 0; i < n-1; i++)
        {
            ans = max(ans, leftProfit[i] + rightProfit[i+1]);
        }

        return ans;
    }
};