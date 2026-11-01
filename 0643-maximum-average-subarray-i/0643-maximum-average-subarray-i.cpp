class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        double maxSum=-1e9;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
            maxSum=max(sum,maxSum);
            }
            j++;

        }
        return maxSum/k;
    }
};