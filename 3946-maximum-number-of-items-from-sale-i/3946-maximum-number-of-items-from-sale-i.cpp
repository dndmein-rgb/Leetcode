class Solution {
public:
    int n;
    vector<int> cnt;
    int dp[1001][1501][2];

    int helper(int i, int budget, int taken,
               vector<vector<int>>& items) {

        if (i == n) return 0;

        int &ans = dp[i][budget][taken];
        if (ans != -1) return ans;

        ans = 0;

        int price = items[i][1];

        if (taken == 0) {

            ans = helper(i + 1, budget, 0, items);

            if (budget >= price) {
                ans = max(ans,
                          1 + cnt[i] +
                          helper(i, budget - price, 1, items));
            }
        }
        else {

            ans = helper(i + 1, budget, 0, items);

            if (budget >= price) {
                ans = max(ans,
                          1 +
                          helper(i, budget - price, 1, items));
            }
        }

        return ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        n = items.size();
        cnt.assign(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0)
                    cnt[i]++;
            }
        }

        memset(dp, -1, sizeof(dp));

        return helper(0, budget, 0, items);
    }
};