class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0,rotten=0,minutes=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)total++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
         int dx[4]={0,0,-1,1};
            int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int sz=q.size();
            rotten+=sz;
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
            q.pop();
           
            for(int d=0;d<4;d++ ){
                int nr=dx[d]+r;
                int nc=dy[d]+c;
                if(nr<0 ||nc<0 ||nr>=n||nc>=m || grid[nr][nc]!=1 )continue;
                q.push({nr,nc});
                grid[nr][nc]=2;
            }
            }
            if(!q.empty())minutes++;

        }
        return total==rotten?minutes:-1;
    }
};