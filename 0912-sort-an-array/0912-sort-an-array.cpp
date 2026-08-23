class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        // pick random pivot
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];

        // partition
        int i = left, j = right;
        while (i <= j) {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        // recursive calls
        if (left < j) quickSort(nums, left, j);
        if (i < right) quickSort(nums, i, right);
    }
};
