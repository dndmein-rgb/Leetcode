class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int rem=vec[0]%x;
        for(int v:vec){
            if(v%x!=rem)return -1;
        }
        sort(vec.begin(),vec.end());
        int ops=0;
        int target=vec[vec.size()/2];
        for(int num:vec){
            ops+=(abs(num-target)/x);
        }
        return ops;
    }
};