class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff=1e9;
        if (n == 1)
            return 0;
      
        for (int i = 0; i + k - 1 < n; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }
    return minDiff;
    }
};