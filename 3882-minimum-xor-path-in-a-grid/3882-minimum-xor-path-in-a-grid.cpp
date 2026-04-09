class Solution {
public:
    int n, m;
    int ans = INT_MAX;

    vector<vector<bitset<1024>>> vis;

    void dfs(int i, int j, int xr, vector<vector<int>>& grid) {
        if (i >= n || j >= m) return;

        xr ^= grid[i][j];

        // prune
        if (vis[i][j][xr]) return;
        vis[i][j][xr] = 1;

        if (i == n-1 && j == m-1) {
            ans = min(ans, xr);
            return;
        }

        dfs(i+1, j, xr, grid);
        dfs(i, j+1, xr, grid);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<bitset<1024>>(m));

        dfs(0, 0, 0, grid);
        return ans;
    }
};