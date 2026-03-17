class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]==1 && row>0){
                    matrix[row][col]+=matrix[row-1][col];
                }
            }
            vector<int>currRow=matrix[row];
            sort(currRow.begin(),currRow.end(),greater<int>());
            for(int col=0;col<m;col++){
                int base=col+1;
                int height=currRow[col];
                result=max(result,base*height);
            }
        }
        return result;
    }
};