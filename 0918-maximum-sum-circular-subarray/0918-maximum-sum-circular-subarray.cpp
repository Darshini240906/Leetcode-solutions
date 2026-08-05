class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;
        int currmax=0,maxSum=INT_MIN;
        int currmin=0,minSum=INT_MAX;

        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];

            currmax+=nums[i];
            maxSum=max(maxSum,currmax);
            if(currmax<0){
                currmax=0;
            }

            currmin+=nums[i];
            minSum=min(minSum,currmin);
            if(currmin>0){
                currmin=0;
            }


        
        }

        if(maxSum<0)return maxSum;

        return max(maxSum,totalSum-minSum);

    }
};