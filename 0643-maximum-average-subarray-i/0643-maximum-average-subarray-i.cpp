class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        double sum=0;
        double maxSum=INT_MIN;
        while(j<n){
            sum+=nums[j];
            if(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
                maxSum=max(maxSum,sum);
            }
            j++;
        }
        cout<<maxSum;
        return maxSum/double(k);
    }
};