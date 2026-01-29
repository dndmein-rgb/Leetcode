class Solution {
public:
void dijkstra(int source, vector<vector<pair<int,int>>>&adj, vector<vector<int>>&dist){
    dist[source][source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();
        if(d>dist[source][u])continue;
        for(auto& i :adj[u]){
            int cost=i.first;
            int v=i.second;
            if(dist[source][v]>dist[source][u]+cost){
                dist[source][v]=dist[source][u]+cost;
                pq.push({dist[source][v],v});
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(26);
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u].push_back({cost[i],v});
        }
        vector<vector<int>>dist(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            dijkstra(i,adj,dist);
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dist[u][v]!=1e9)ans+=dist[u][v];
            else return -1;
        }
        return ans;
    }
};