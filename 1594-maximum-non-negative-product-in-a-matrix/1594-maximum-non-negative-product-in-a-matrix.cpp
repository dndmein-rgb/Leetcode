class Solution {
public:
    int n, m;
    typedef long long ll;
    vector<vector<pair<ll, ll>>> t;
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1)
            return {grid[i][j], grid[i][j]};
            if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX))return t[i][j];
             ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
       if(i+1 < n) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }


        //Right
        if(j+1 < m) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};

    }
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int mod = 1e9 + 7;
        t = vector<vector<pair<ll, ll>>>(
            n, vector<pair<ll, ll>>(m, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);
        return maxProd < 0 ? -1 : maxProd % mod;
    }
};