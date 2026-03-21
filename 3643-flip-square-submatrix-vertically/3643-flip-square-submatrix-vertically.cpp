class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int i=x;
        int j=x+k-1;
        while(i<j){
            for(int c=y;c<=y+k-1;c++){
                cout<<grid[i][c]<<grid[j][c];
                swap(grid[i][c],grid[j][c]);
            }
            i++;
            j--;
        }
        return grid;
    }
};