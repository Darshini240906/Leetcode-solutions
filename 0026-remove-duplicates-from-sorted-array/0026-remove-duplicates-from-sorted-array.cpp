class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
    
    int j = 0; // Pointer for the next unique element
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
    }
};