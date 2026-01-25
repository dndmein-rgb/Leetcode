class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
       int n=nums.size() ;
        int lastIdx=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1])lastIdx=i;
        }
        // cout<<lastIdx;
        return lastIdx==-1?0:lastIdx+1;
    }
};