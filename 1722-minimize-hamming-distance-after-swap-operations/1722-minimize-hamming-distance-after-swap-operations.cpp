class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>>adj(n);
        for(auto& e:allowedSwaps){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
            int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            vector<int>comp;
            queue<int>q;
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                comp.push_back(node);
                for(int nei:adj[node]){
                    if(!vis[nei]){
                        vis[nei]=true;
                        q.push(nei);
                    }
                }
            }
            unordered_map<int,int>freq;
            for(int idx:comp){
                freq[source[idx]]++;
            }
            for(int idx:comp){
                if(freq[target[idx]]>0)freq[target[idx]]--;
            
            else ans++;
            }
        }
        return ans;
    }
};