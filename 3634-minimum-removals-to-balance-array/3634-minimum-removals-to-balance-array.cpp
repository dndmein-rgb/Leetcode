class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            long long limit=(long long)nums[i]*k;
            int j=upper_bound(nums.begin()+1,nums.end(),limit)-nums.begin();
            ans = min(ans, n - (j - i));
        }

        return ans;
    }
};
