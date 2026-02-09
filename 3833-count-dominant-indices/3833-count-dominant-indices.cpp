class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();  
        int sums=0,count=0;
        for(int i=n-2;i>=0;i--){
            sums+=nums[i+1];
            if(nums[i]>sums/(n-i-1))count++;
        }
        return count;
    }
};