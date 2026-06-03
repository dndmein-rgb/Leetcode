class Solution {
public:
int t[201][10001];
int n;
    bool solve(int i,int target,vector<int>&nums){
        if(target==0)return true;
        if(i==n)return false;
        if(t[i][target]!=-1)return t[i][target];
        if(nums[i]==target)return true;

        bool notTake=solve(i+1,target,nums);
        bool take=false;
        if(target>=nums[i]){
            take=solve(i+1,target-nums[i],nums);
        }
        return t[i][target]= take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0)return false;
        int target=total/2;
        return solve(0,target,nums);
    }
};