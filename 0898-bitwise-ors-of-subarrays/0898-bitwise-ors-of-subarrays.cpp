class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;      // Stores all distinct OR values
        unordered_set<int> prev;     // OR values of subarrays ending at previous index

        for (int num : arr) {
            unordered_set<int> curr;

            // Start a new subarray
            curr.insert(num);

            // Extend all previous subarrays
            for (int x : prev) {
                curr.insert(x | num);
            }

            // Add current OR values to the final answer
            for (int x : curr) {
                ans.insert(x);
            }

            prev = curr;
        }

        return ans.size();
    }
};