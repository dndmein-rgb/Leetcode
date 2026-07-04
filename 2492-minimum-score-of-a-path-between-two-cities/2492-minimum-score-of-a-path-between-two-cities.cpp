class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void UNION(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1) ;
        for(auto& r:roads){
            dsu.UNION(r[0],r[1]);
        }
        int root=dsu.find(1);
        int  ans=INT_MAX;
        for(auto& r:roads){
            if(dsu.find(r[0])==root)ans=min(ans,r[2]);
        }
        return ans;
    }
};