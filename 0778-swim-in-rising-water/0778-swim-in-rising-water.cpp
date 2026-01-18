class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // min-heap: {current_max_height, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int i = cur[1];
            int j = cur[2];

            if (visited[i][j]) continue;
            visited[i][j] = true;

            if (i == n - 1 && j == n - 1)
                return time;

            for (auto& d : directions) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj])
                    continue;

                int nextTime = max(time, grid[ni][nj]);
                pq.push({nextTime, ni, nj});
            }
        }

        return -1; 
    }
};
