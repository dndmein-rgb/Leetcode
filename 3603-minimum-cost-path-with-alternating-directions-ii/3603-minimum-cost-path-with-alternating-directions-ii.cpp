class Solution {
public:
    const long long INF = 1e15;

    long long solve(int m, int n, int i, int j, int parity,
                    vector<vector<int>>& waitCost,
                    vector<vector<vector<long long>>>& dp) {

        if (i >= m || j >= n)
            return INF;

        if (i == m - 1 && j == n - 1)
            return 0;  // no extra cost after reaching destination

        if (dp[i][j][parity] != -1)
            return dp[i][j][parity];

        long long ans = INF;

        if (parity == 0) {
            // even second → must wait
            ans = waitCost[i][j] +
                  solve(m, n, i, j, 1, waitCost, dp);
        } else {
            // odd second → must move

            // move down
            long long down = (1LL * (i + 2) * (j + 1)) +
                             solve(m, n, i + 1, j, 0, waitCost, dp);

            // move right
            long long right = (1LL * (i + 1) * (j + 2)) +
                              solve(m, n, i, j + 1, 0, waitCost, dp);

            ans = min(down, right);
        }

        return dp[i][j][parity] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, -1)));

        // Start at (0,0) on second 1 → parity = 1 (odd → move)
        long long startCost = 1LL * 1 * 1;  // entry cost of (0,0)

        return startCost +
               solve(m, n, 0, 0, 1, waitCost, dp);
    }
};