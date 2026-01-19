class Solution {
public:
    bool check( int k,int i, int j,  int threshold,vector<vector<int>>& prefix) {
        int n = prefix.size()-1;
        int m = prefix[0].size()-1;

        if(i+k> n || j+k>m){
            return false;
        }
        int sum = prefix[i+k][j+k]-prefix[i+k][j-1]-prefix[i-1][j+k]+prefix[i-1][j-1];
        return sum<=threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;

        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j]=mat[i-1][j-1];
                prefix[i][j]+=prefix[i-1][j];
                prefix[i][j]+=prefix[i][j-1];
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }

        

        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= m; j++) {
                int low =maxi;
                int high = min(n,m);

                while(low<=high){
                    int mid =(low+high)/2;
                    if(check(mid,i,j,threshold,prefix)){
                        low =mid+1;
                        maxi =max(maxi,mid+1);
                    }else{
                        high =mid-1;
                    }
                }
            }
        }

        return maxi;
    }
};