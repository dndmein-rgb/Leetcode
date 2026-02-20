class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        return (long)nums[0] * nums[1]*100000;
    }
};