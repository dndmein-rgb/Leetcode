class Solution {
public:
typedef long long ll;
    bool canReduce(long long k,vector<int>&nums){
        ll limit=k*k,totalOps=0;
        for(int num:nums){
            totalOps+=(num+k-1)/k;
            if(totalOps>limit)return false;
        }
        return totalOps<=limit;
    }
    int minimumK(vector<int>& nums) {
        int low=1,high=100000;
        int result=nums[0];
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(canReduce(mid,nums)){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return result;
    }
};