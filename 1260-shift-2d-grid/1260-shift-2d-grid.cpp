class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        k %= (n * m);

        if (k == 0)
            return grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int row = i + (j + k) / m;
                int col = (j + k) % m;

                row %= n;

                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};