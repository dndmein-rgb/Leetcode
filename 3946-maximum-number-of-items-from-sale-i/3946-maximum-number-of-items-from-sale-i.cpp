class Solution {
public:
    int n;
    vector<int> price, val;
    vector<vector<int>> dp;

    int solve(int i, int budget) {
        if (i == n) return 0;

        if (dp[i][budget] != -1)
            return dp[i][budget];

        int ans = solve(i + 1, budget);

        // first purchase of item i
        if (budget >= price[i]) {
            ans = max(ans,
                      val[i] +
                      solve(i + 1, budget - price[i]));
        }

        return dp[i][budget] = ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();

        price.resize(n);
        val.resize(n);

        int mnPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            price[i] = items[i][1];
            mnPrice = min(mnPrice, price[i]);

            int freebies = 0;
            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0)
                    freebies++;
            }

            val[i] = freebies + 1;
        }

        dp.assign(n, vector<int>(budget + 1, -1));

        int ans = 0;

        for (int spent = 0; spent <= budget; spent++) {
            int cur = solve(0, spent);

            // spend remaining money on cheapest item
            cur += (budget - spent) / mnPrice;

            ans = max(ans, cur);
        }

        return ans;
    }
};