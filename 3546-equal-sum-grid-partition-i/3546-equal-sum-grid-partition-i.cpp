class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
       double totalSum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalSum+=grid[i][j];
            }
        }
        long long currSum=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                currSum+=grid[i][j];
            }
            if(totalSum/2.0==currSum)return true;
        }
        currSum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                currSum+=grid[i][j];
            }
             if(totalSum/2.0==currSum)return true;
        }
        return false;
    }
};