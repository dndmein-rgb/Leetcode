class DSU{
    public:
    vector<int>parent,rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void UNION(int x,int y){
        int x_parent = find(x);
int y_parent = find(y);
        if(x_parent==y_parent)return ;

        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else {
             parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
         DSU dsu(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.UNION(i,j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i)provinces++;
        }
        return provinces;

    }
};