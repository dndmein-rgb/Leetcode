class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int minLen=n+1;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minLen=min(minLen,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minLen==n+1?0:minLen;
    }
};