class Solution {
public:
int t[2501][2501];
int n;
int solve(int i,int prev,vector<int>&nums){
    if(i==n)return 0;
    if(t[i][prev+1]!=-1)return t[i][prev+1];
    int notTake=solve(i+1,prev,nums);
    int take=0;
    if(prev==-1 ||nums[prev]<nums[i]){
        take=1+solve(i+1,i,nums);
    }
    return t[i][prev+1]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};