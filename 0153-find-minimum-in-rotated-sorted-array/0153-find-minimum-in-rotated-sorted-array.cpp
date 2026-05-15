class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[j]){
                ans=min(ans,nums[j]);
                i=mid+1;
            }else if(nums[mid]>=nums[i] && nums[mid]<=nums[j])return nums[i];
            else  j=mid;
        }
        return ans;
    }
};