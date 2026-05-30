class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void UNION(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(256);
        for(auto& e:equations){
            if(e[1]=='='){
                    dsu.UNION(e[0],e[3]);
            }
        }
         for(auto& e:equations){
            if(e[1]=='!'){
                    if(dsu.find(e[0])==dsu.find(e[3]))return false;
            }

        }
        return true;
    }
};