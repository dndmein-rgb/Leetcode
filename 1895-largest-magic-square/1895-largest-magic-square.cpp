class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> rowSum(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < cols; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }
        vector<vector<int>> colSum(rows, vector<int>(cols));
        for(int j=0;j<cols;j++){
            colSum[0][j]=grid[0][j];
            for(int i=1;i<rows;i++){
                colSum[i][j]=colSum[i-1][j]+grid[i][j];
            }
        }
        for(int side=min(rows,cols);side>=2;side--){
          for (int i = 0; i + side - 1 < rows; ++i) {
                for (int j = 0; j + side - 1 < cols; ++j) {
                    int target=rowSum[i][j+side-1]-(j>0?rowSum[i][j-1]:0);
                    bool AllSame=true;

                    //check rows
                    for(int r=i+1;r<i+side;r++){
                        int rSum=rowSum[r][j+side-1]-(j>0?rowSum[r][j-1]:0);
                        if(rSum!=target){
                            AllSame=false;
                            break;
                        }
                    }
                    if(!AllSame)continue;
                    for(int c=j+1;c<j+side;c++){
                        int cSum=colSum[i + side - 1][c] - (i > 0 ? colSum[i - 1][c] : 0);

                        if(cSum!=target){
                            AllSame=false;
                            break;
                        }
                    }
                      if(!AllSame)continue;
                      int diag=0,antiDiag=0;
                      for(int k=0;k<side;k++){
                        diag+=grid[i+k][j+k];
                        antiDiag+=grid[i+k][j+side-k-1];
                      }
                       if (diag == target && antiDiag == target) {
                        return side;
                }
            }
        }
        }
        return 1;
    }
};