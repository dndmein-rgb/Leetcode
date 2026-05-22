class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0,rotten=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                    if(grid[i][j]!=0)
                total++;
            }
        }
         int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            rotten+=sz;
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=r+dx[k];
                    int ny=c+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                    }
                }
            }
            if(!q.empty())time++;
        }
        return total==rotten ?time : -1;
    }
};