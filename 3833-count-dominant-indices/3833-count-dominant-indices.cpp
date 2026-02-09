class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>sums(n);
        int curr=0;
        for(int i=n-1;i>=0;i--){
            curr=curr+nums[i];
            sums[i]=curr;
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            double avg=sums[i+1]/(n-1-i);
            if(nums[i]>avg)count++;
           
        }
        return count;
    }
};