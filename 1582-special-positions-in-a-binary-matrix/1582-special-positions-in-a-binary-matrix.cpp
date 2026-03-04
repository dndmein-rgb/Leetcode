class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    bool flag = true;
                    for (int k = 0; k < m; k++) {
                        if (j != k && mat[i][k] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    for (int l = 0; l < n; l++) {
                        if (i != l && mat[l][j] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                }
            }
        }
    
 return count;
}
}
;