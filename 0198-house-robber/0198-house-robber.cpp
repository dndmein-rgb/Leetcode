class Solution {
public:
int t[101];
int n;
int solve(int i,vector<int>&nums){
    if(i>n-1)return 0;
    if(t[i]!=-1)return t[i];
    int take=nums[i]+solve(i+2,nums);
    int skip=solve(i+1,nums);
    return t[i]=max(take,skip);
}
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};