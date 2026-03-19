class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> currSumX(n, vector<int>(m, 0));
        vector<vector<int>> currSumY(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                currSumX[i][j] = (grid[i][j] == 'X');
                currSumY[i][j] = (grid[i][j] == 'Y');
                if (i > 0) {
                    currSumX[i][j] += currSumX[i - 1][j];
                    currSumY[i][j] += currSumY[i - 1][j];
                }
                if (j > 0) {
                    currSumX[i][j] += currSumX[i][j - 1];
                    currSumY[i][j] += currSumY[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    currSumX[i][j] -= currSumX[i - 1][j - 1];
                    currSumY[i][j] -= currSumY[i - 1][j - 1];
                }
                if (currSumX[i][j] == currSumY[i][j] && currSumX[i][j] > 0) {
                    count++;
                }
            }
        }
        return count;
    }
};