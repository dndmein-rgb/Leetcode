class Solution {
public:
//  vector<int>parent,rank;
//         int find(int x){
//             if(x==parent[x])return x;
//             return parent[x]=find(parent[x]);
//         }
//         void Union(int x, int y) {
//         int x_parent = parent[x];
//         int y_parent = parent[y];
//         if (x_parent == y_parent)
//             return;
//         if (rank[x_parent] > rank[y_parent]) {
//             parent[y_parent] = x_parent;
//         } else if (rank[y_parent] > rank[x_parent]) {
//             parent[x_parent] = y_parent;
//         } else {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++;
//         }
//     }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       vector<int>comp(n,0);
       for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]<=maxDiff)
        comp[i]=comp[i-1];
       
       else comp[i]=comp[i-1]+1;
       }
        vector<bool>ans;
        for(auto& q:queries){
            int u=comp[q[0]];
            int v=comp[q[1]];
           ans.push_back(u==v);
        }
        return ans;
    }
};