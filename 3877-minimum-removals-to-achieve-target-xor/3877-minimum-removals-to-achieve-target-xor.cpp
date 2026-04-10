class Solution {
public:
int n;
int t[41][16384];
int solve(int i,int xr,vector<int>&nums,int target){
    if(i==n)return xr==target ? 0 : -1e9;
    if(t[i][xr]!=-1)return t[i][xr];

    int take=1+solve(i+1,xr^nums[i],nums,target);
    int notTake=solve(i+1,xr,nums,target);
    return t[i][xr]=max(take,notTake);
}
    int minRemovals(vector<int>& nums, int target) {
         n=nums.size();
         memset(t,-1,sizeof(t));
        int member=solve(0,0,nums,target);
        if(member<0)return -1;
        return n-member;
    }
};