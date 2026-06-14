class Solution {
public:
vector<vector<long long >>dp;
    long long func(int idx, vector<int>& nums, string &s, int taken){
        int n = nums.size();
        if(idx>=n) return 0;
        if(dp[idx][taken]!=-1)return dp[idx][taken];
        
        //skip
        long long best = func(idx+1,nums,s,0);
        //token already present
        if(s[idx]=='1' && !taken){
            best = max(best, nums[idx]+func(idx+1,nums,s,0));
        }
        //move i+1 to i
        if(idx+1<n && s[idx+1]=='1'){
            best = max(best, nums[idx]+func(idx+1,nums,s,1));
        }
        
        return dp[idx][taken]= best;
    }
    
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        dp.assign(n,vector<long long>(2,-1));
        return func(0,nums,s,0);
    }
};