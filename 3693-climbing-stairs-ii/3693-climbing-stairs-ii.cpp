class Solution {
public:
    vector<long long> dp;

    long long solve(int i, int n, vector<int>& costs) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        long long ans = LLONG_MAX;

        for (int jump = 1; jump <= 3; jump++) {
            int j = i + jump;
            if (j <= n) {
                long long cost = costs[j - 1] + 1LL * jump * jump
                                 + solve(j, n, costs);
                ans = min(ans, cost);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n + 1, -1);
        return solve(0, n, costs);
    }
};