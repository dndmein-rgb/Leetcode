class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> r[3];
        for (int x : nums) {
            r[x % 3].push_back(x);
        }
        for (int i = 0; i < 3; i++) {
            sort(r[i].rbegin(), r[i].rend());
        }
        int ans = 0;
        // 1+1+1
        if (r[0].size() >= 3) {
            ans = max(ans, r[0][0] + r[0][1] + r[0][2]);
        }
        // 2+2+2

        if (r[1].size() >= 3) {
            ans = max(ans, r[1][0] + r[1][1] + r[1][2]);
        }
        // 3+3+3
        if (r[2].size() >= 3) {
            ans = max(ans, r[2][0] + r[2][1] + r[2][2]);
        }

        // 0+1+2;
        if (!r[0].empty() && !r[1].empty() && !r[2].empty()) {
            ans = max(ans, r[0][0] + r[1][0] + r[2][0]);
        }

        return ans;
    }
};