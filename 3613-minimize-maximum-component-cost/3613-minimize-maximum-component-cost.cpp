class Solution {
public:
    vector<int> parent, rank;

    int Find(int x){
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        int px = Find(x);
        int py = Find(y);

        if(px == py) return;

        if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {

        if(k >= n) return 0;

        sort(edges.begin(), edges.end(),
            [](auto &a, auto &b){
                return a[2] < b[2];
            });

        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++)
            parent[i] = i;

        int components = n;
        int answer = 0;

        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];

            if(Find(u) != Find(v)){
                Union(u,v);
                components--;
                answer = w;

                if(components == k)
                    return answer;
            }
        }

        return 0;
    }
};