class Solution {
public:
    int countOperations(vector<int>&nums,int mid){
        int operations=0;
        for(int num:nums){
            operations+=(num+mid-1)/mid;
        }
        return operations;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long  l = 1, r = 100000;
        int ans=nums[0];
        while (l<=r){
            long long  mid=l+(r-l)/2;
            if(countOperations(nums,mid)<=mid*mid){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};