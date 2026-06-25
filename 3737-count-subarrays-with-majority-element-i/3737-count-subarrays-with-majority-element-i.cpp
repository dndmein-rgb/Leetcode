class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        for (int i=0;i<n;i++){
            int majority=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target)majority++;
                int length=j-i+1;
                if(2*majority>length)count++;
            }
        }
        return count;
    }
};