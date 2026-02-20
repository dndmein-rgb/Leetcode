class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        vector<bool> inc(n, false);
        vector<bool> dec(n, false);

        // strictly increasing from left
        inc[0] = true;
        for (int i = 1; i < n; i++) {
            inc[i] = inc[i - 1] && (nums[i] > nums[i - 1]);
        }

        // strictly decreasing from right
        dec[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            dec[i] = dec[i + 1] && (nums[i] > nums[i + 1]);
        }

        // prefix sums
        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        long long total = pref[n - 1];
        long long ans = LLONG_MAX;
        bool found = false;

        for (int i = 0; i < n - 1; i++) {
            if (inc[i] && dec[i + 1]) {
                long long leftSum = pref[i];
                long long rightSum = total - leftSum;
                ans = min(ans, llabs(leftSum - rightSum));
                found = true;
            }
        }

        return found ? ans : -1;
    }
};