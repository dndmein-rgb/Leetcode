class Solution {
public:
    long long solve(int m, int n, int i, int j, int time,
                    vector<vector<int>>& waitCost,
                    vector<vector<vector<long long>>>& dp) {
        if (i >= m || j >= n)
            return 1e15;
        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j][time % 2] != -1)
            return dp[i][j][time % 2];

        long long ans;
        if (time % 2 == 0) {
            ans = waitCost[i][j] + solve(m, n, i, j, time + 1, waitCost, dp);
        } else {
            long long right = ((i + 1) + 1) * (j + 1) +
                              solve(m, n, i + 1, j, time + 1, waitCost, dp);
            long long down = (i + 1) * ((j + 1) + 1) +
                             solve(m, n, i, j + 1, time + 1, waitCost, dp);
            ans = min(right, down);
        }

        return dp[i][j][time % 2] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return solve(m, n, 0, 0, 1, waitCost, dp);
    }
};