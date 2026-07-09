class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])<=maxDiff && dsu.find(i)!=dsu.find(i-1))dsu.UNION(i,i-1);
        }
        vector<bool>ans;
        for(auto& q:queries){
            int u=q[0];
            int v=q[1];
            ans.push_back(dsu.find(u)==dsu.find(v));
        }
        return ans;
    }
};