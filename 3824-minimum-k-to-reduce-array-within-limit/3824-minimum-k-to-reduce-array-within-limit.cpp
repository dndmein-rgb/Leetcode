class Solution {
public:
    bool canReduce(vector<int>&nums,long long k){
        if(k==0)return false;
        long long totalOps=0,limit=k*k;
        for(int num:nums){
            totalOps+=(num+k-1)/k;
            if(totalOps>limit)return false;
        }
        return totalOps<=limit;
    }
    int minimumK(vector<int>& nums) {
       long long low=1,high=100000;
        int result=high;
        while(low<=high){
            long long mid=low +(high-low)/2;
            if(canReduce(nums,mid)){
                result=mid;
                high=mid-1;
            }
            else{
            low=mid+1;}
        }
        return result;
    }
};