class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=-1e9,currSum=0;
        for(int num:nums){
            currSum+=num;
            if(num>currSum)currSum=num;
            maxSum=max(maxSum,currSum);

        }
        return maxSum;

    }
};