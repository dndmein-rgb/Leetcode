class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();  
        int sums=nums[n-1],count=0;
        for(int i=n-2;i>=0;i--){
           
            if(nums[i]>sums/(n-i-1))count++;
             sums+=nums[i];
        }
        return count;
    }
};