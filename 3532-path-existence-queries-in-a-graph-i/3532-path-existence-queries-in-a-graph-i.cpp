class Solution {
public:
 vector<int>parent,rank;
        int find(int x){
            if(x==parent[x])return x;
            return parent[x]=find(parent[x]);
        }
        void Union(int x, int y) {
        int x_parent = parent[x];
        int y_parent = parent[y];
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=maxDiff && find(i+1)!=find(i)){
                Union(i,i+1);
            }
        }
        vector<bool>ans;
        for(auto& q:queries){
            int u=q[0];
            int v=q[1];
            if(find(u)==find(v))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};