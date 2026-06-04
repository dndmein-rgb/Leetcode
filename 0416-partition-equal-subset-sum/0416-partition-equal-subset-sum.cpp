class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<bool>> dp(n + 1,
                                vector<bool>(target + 1, false));

        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Filling from back because dp[i] depends on dp[i+1]
        for(int i = n - 1; i >= 0; i--) {

            for(int t = 1; t <= target; t++) {

                bool notTake = dp[i + 1][t];

                bool take = false;

                if(t >= nums[i]) {
                    take = dp[i + 1][t - nums[i]];
                }

                dp[i][t] = take || notTake;
            }
        }

        return dp[0][target];
    }
};