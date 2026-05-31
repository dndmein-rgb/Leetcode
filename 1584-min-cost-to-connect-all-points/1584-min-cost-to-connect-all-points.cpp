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

    bool UNION(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (rank[pu] < rank[pv])
            swap(pu, pv);

        parent[pv] = pu;

        if (rank[pu] == rank[pv])
            rank[pu]++;

        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int cost =
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);

                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int mstCost = 0;
        int edgesUsed = 0;

        for (auto &e : edges) {

            int cost = e[0];
            int u = e[1];
            int v = e[2];

            if (dsu.UNION(u, v)) {

                mstCost += cost;
                edgesUsed++;

                if (edgesUsed == n - 1)
                    break;
            }
        }

        return mstCost;
    }
};