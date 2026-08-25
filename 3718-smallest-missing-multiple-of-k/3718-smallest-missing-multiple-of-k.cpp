class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i : nums) {
            st.insert(i); // mark presence
        }

        int mul = 1;
        while (st.find(mul * k) != st.end()) {
            mul++;
        }
        return mul * k;
    }
};
