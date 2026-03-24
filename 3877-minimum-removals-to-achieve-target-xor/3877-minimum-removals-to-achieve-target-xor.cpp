class Solution {
public:
int n;
const int NEG=-1e9;
int dp[41][16384];
int solve(int i,int xr ,vector<int>&nums,int target){
    if(i==n)return xr==target ? 0 : NEG;
    if(dp[i][xr]!=-1)return dp[i][xr];
    int skip=solve(i+1,xr,nums,target);
    int take=1+solve(i+1,xr^nums[i],nums,target);
    return dp[i][xr]=max(take,skip);
}
    int minRemovals(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
       int kept= solve(0,0,nums,target);
       if(kept<0)return -1;
       return n-kept;
    }
};