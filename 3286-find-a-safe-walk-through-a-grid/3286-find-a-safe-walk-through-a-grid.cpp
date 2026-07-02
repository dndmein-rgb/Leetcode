class Solution {
public:
    int m, n;

    // -1 = uncomputed, 0 = false, 1 = true
    vector<vector<vector<int>>> dp;
    vector<vector<vector<bool>>> vis;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    bool solve(int r, int c, int health, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;

        health -= grid[r][c];

        if (health <= 0)
            return false;

        if (r == m - 1 && c == n - 1)
            return true;

        if (dp[r][c][health] != -1)
            return dp[r][c][health];

        if (vis[r][c][health])
            return false; // avoid infinite cycle

        vis[r][c][health] = true;

        bool ans = false;

        for (int k = 0; k < 4 && !ans; k++) {
            ans |= solve(r + dr[k], c + dc[k], health, grid);
        }

        vis[r][c][health] = false;

        return dp[r][c][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m,
                  vector<vector<int>>(n,
                  vector<int>(health + 1, -1)));

        vis.assign(m,
                   vector<vector<bool>>(n,
                   vector<bool>(health + 1, false)));

        return solve(0, 0, health, grid);
    }
};