class Solution {
public:
    void build(int start, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;

            temp.push_back(candidates[i]);

            // stay on same index → allows reuse
            build(i, candidates, target - candidates[i], temp, result);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        build(0, candidates, target, temp, result);

        return result;
    }
};