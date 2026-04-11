class Solution {
public:
vector<int>bfs(int start,int n,vector<vector<int>>&adj){
    queue<int>q;
    vector<int>dist(n,-1);
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
            q.push(v);
            }
        }
    }
    return dist;
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dx=bfs(x,n,adj);
        vector<int>dy=bfs(y,n,adj);
        vector<int>dz=bfs(z,n,adj);
        long long specialCount=0;
        for(int i=0;i<n;i++){
            long long d[3]={dx[i],dy[i],dz[i]};
            sort(d,d+3);
            if(d[2]*d[2]==d[1]*d[1] + d[0]*d[0]){
                specialCount++;
            };
        }
        return specialCount;
    }
};