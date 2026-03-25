class Solution {
public:
typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        ll totalSum=0;
        vector<ll>rowSum(n,0);
        vector<ll>colSum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalSum+=grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }
        ll curr=0;
        for(int i=0;i<n;i++){
            curr+=rowSum[i];
            if(totalSum-curr==curr)return true;
        }
        curr=0;
        for(int j=0;j<m;j++){
            curr+=colSum[j];
            if(totalSum-curr==curr)return true;
        }
        return false;

    }
};