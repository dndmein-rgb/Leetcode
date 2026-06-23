#include <vector>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int range_sz = r - l + 1;

        if (range_sz < 2) return 0;

        // Use 1D vectors for cache friendliness and minimal memory footprint
        // dp[0][v], dp[1][v], dp[2][v] flattened into a single vector of size 3 * range_sz
        vector<int> dp(3 * range_sz, 1);
        vector<int> next_dp(3 * range_sz, 0);

        // Reusable vectors for prefix sums to avoid re-allocation inside the loop
        vector<long long> pref_dir1(range_sz, 0);
        vector<long long> pref_dir2(range_sz, 0);

        // Iterate backwards from idx = n - 2 down to 0
        for (int idx = n - 2; idx >= 0; idx--) {
            long long sum1 = 0, sum2 = 0;
            for (int v = 0; v < range_sz; v++) {
                sum1 = (sum1 + dp[1 * range_sz + v]) % MOD;
                sum2 = (sum2 + dp[2 * range_sz + v]) % MOD;
                pref_dir1[v] = sum1;
                pref_dir2[v] = sum2;
            }

            for (int prev = 0; prev < range_sz; prev++) {
                // Case dir == 1: Last was UP -> Next must be DOWN (cur < prev)
                if (prev > 0) {
                    next_dp[1 * range_sz + prev] = pref_dir2[prev - 1];
                } else {
                    next_dp[1 * range_sz + prev] = 0;
                }

                // Case dir == 2: Last was DOWN -> Next must be UP (cur > prev)
                if (prev < range_sz - 1) {
                    next_dp[2 * range_sz + prev] = (pref_dir1[range_sz - 1] - pref_dir1[prev] + MOD) % MOD;
                } else {
                    next_dp[2 * range_sz + prev] = 0;
                }

                // Case dir == 0: Starting state at idx == 0
                if (idx == 0) {
                    long long up_options = (prev < range_sz - 1) ? (pref_dir1[range_sz - 1] - pref_dir1[prev] + MOD) % MOD : 0;
                    long long down_options = (prev > 0) ? pref_dir2[prev - 1] : 0;
                    next_dp[0 * range_sz + prev] = (up_options + down_options) % MOD;
                }
            }
            dp = next_dp;
        }

        // Aggregate answers for all valid starting values
        long long total_ans = 0;
        for (int v = 0; v < range_sz; v++) {
            total_ans = (total_ans + dp[0 * range_sz + v]) % MOD;
        }

        return total_ans;
    }
};