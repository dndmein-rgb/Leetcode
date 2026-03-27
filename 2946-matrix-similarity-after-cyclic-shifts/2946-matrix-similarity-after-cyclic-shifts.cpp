class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
         if(k == 0) { 
            return true;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currIdx=j;
                int finalIdx;
                if(i%2==0){
                    finalIdx=(j+k)%m;
                }
                else finalIdx=(j-k+m)%m;
            
            if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }
            }
        }
        return true;
    }
};