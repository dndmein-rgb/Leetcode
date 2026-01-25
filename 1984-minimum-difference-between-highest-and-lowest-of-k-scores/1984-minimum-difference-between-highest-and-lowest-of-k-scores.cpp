class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int minDiff=1e9;
        if (n == 1)
            return 0;
       int i=0,j=0;
       while(j<n){
        if(j-i+1>k){
        i++;
       }
        if(j-i+1==k)
        minDiff=min(minDiff,abs(nums[j]-nums[i]));
       
       
       j++;
       
    }
    return minDiff;
    }
};