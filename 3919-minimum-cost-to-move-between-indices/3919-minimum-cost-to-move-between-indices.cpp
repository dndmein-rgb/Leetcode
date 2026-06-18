class Solution {
public:
    vector<int> minCost(vector<int>& nums,
                              vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> closest(n);

        closest[0] = 1;
        closest[n - 1] = n - 2;

        for (int i = 1; i < n - 1; i++) {
            long long left = nums[i] - nums[i - 1];
            long long right = nums[i + 1] - nums[i];

            closest[i] = (left <= right) ? i - 1 : i + 1;
        }

        vector<long long> pref(n, 0);

        for (int i = 0; i < n - 1; i++) {
            long long cost =
                (closest[i] == i + 1)
                ? 1
                : (long long)nums[i + 1] - nums[i];

            pref[i + 1] = pref[i] + cost;
        }

        vector<long long> suff(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            long long cost =
                (closest[i + 1] == i)
                ? 1
                : (long long)nums[i + 1] - nums[i];

            suff[i] = suff[i + 1] + cost;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r)
                ans.push_back(pref[r] - pref[l]);
            else
                ans.push_back(suff[r] - suff[l]);
        }

        return ans;
    }
};