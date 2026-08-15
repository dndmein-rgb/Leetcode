class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int X=0;
        int zeros=0;
        for(int i=0;i<n;i++){
            X^=nums[i];
            if(nums[i]==0)zeros++;
        }
        if(X!=0)return n;
        if(zeros==n)return 0;
        return n-1;
    }
};