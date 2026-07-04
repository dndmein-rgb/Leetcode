class Solution {
public:
int ans=INT_MAX;
void dfs(int i,vector<vector<pair<int,int>>>&adj,vector<vector<int>>&roads,vector<bool>&vis){

    vis[i]=true;
    for(auto &[next, wt]:adj[i]){
        ans=min(ans,wt);
        if(!vis[next])dfs(next,adj,roads,vis);
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<bool>vis(n+1);
        for(auto&r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
         dfs(1,adj,roads,vis);
         return ans;
    }
};