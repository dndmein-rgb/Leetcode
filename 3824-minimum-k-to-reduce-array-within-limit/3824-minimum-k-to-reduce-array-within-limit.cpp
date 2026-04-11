class Solution {
public:
long long nonPositives(vector<int>& nums,int k){
    long long totalOps=0;
    for(int num:nums){
        totalOps+=((num+k-1)/k);
    }
    return totalOps;
}
    int minimumK(vector<int>& nums) {
        long long  low=1,high=100000;
        long long ans=0;
        while(low<=high){
            long long  mid=low+(high-low)/2;
            long long limit=mid*mid;
            if(nonPositives(nums,mid)<=limit){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};