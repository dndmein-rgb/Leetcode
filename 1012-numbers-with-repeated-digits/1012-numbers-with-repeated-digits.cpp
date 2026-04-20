class Solution {
public:
    // idx, tight, repetition, leading_zero, mask
    int dp[11][2][2][2][1024];
    bool vis[11][2][2][2][1024];

    int f(string &s, int idx, bool tight, bool repetition, bool lz, int mask) {
        if (idx == s.size()) {
            return repetition; // count this number if repetition found
        }

        if (vis[idx][tight][repetition][lz][mask])
            return dp[idx][tight][repetition][lz][mask];

        vis[idx][tight][repetition][lz][mask] = true;

        int ub = tight ? (s[idx] - '0') : 9;
        int res = 0;

        for (int dig = 0; dig <= ub; dig++) {

            bool newTight = tight && (dig == ub);

            // still in leading zero phase
            if (lz && dig == 0) {
                res += f(s, idx + 1, newTight, repetition, 1, mask);
            }
            else {
                bool isDigitUsed = (mask >> dig) & 1;

                res += f(
                    s,
                    idx + 1,
                    newTight,
                    repetition || isDigitUsed,
                    0,
                    mask | (1 << dig)
                );
            }
        }

        return dp[idx][tight][repetition][lz][mask] = res;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return f(s, 0, 1, 0, 1, 0);
    }
};