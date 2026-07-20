class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(k==0)return grid;
        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=0;i<k;i++){
            for(int j=0;j<m;j++){
                for(int l=0;l<n;l++){
                    if(j==m-1 && l==n-1){
                      ans[0][0] = grid[m - 1][n - 1];
                    }
                   else if(l==n-1){
                       ans[j+1][0]= grid[j][l];
                    }
                    else ans[j][l+1]=grid[j][l];
                }
            }
            grid=ans;
        }
        return ans;
    }
};