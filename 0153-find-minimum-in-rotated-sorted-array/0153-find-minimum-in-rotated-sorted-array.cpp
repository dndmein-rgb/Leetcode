class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int mini=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=nums[j]){
                mini=min(mini,nums[j]);
                i=mid+1;
            }
            else{
                j=mid;
            }

        }
        return mini;
    }
};