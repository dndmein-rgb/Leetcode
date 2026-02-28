class Solution {
public:
vector<long long >dp;
    long long solve(int i,vector<int>& nums, vector<int>& colors){
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long skip=solve(i+1,nums,colors);
        long long take=-1e9;
        if(i+1<n && colors[i]==colors[i+1]){
            take=nums[i]+solve(i+2,nums,colors);
        }else {
            take=nums[i]+solve(i+1,nums,colors);
        }
        return dp[i]=max(take,skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        dp.assign(n,-1);
        return solve(0,nums,colors);
    }
}; 