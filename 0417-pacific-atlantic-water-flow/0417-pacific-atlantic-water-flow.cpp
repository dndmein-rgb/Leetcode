class Solution {
public:

    int n, m;

    vector<vector<int>> dir = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };

    void dfs(int i, int j,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        for(auto &d : dir) {

            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 &&
               ni < n && nj < m &&
               !vis[ni][nj] &&
               heights[ni][nj] >= heights[i][j]) {

                dfs(ni, nj, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        // Pacific
        for(int i = 0; i < n; i++) {
            dfs(i, 0, heights, pac);
        }

        for(int j = 0; j < m; j++) {
            dfs(0, j, heights, pac);
        }

        // Atlantic
        for(int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atl);
        }

        for(int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atl);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};