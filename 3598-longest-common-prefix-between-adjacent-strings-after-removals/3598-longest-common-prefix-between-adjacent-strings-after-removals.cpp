class Solution {
public:
    int getLCP(const string &a, const string &b) {
        int len = min(a.size(), b.size());
        int i = 0;
        while (i < len && a[i] == b[i]) i++;
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);
        if (n <= 2) return ans; // removing leaves <=1 pair → always 0

        // Step 1: compute adjacent LCP
        vector<int> lcp(n - 1);
        for (int i = 0; i < n - 1; i++)
            lcp[i] = getLCP(words[i], words[i + 1]);

        // Step 2: prefix max
        vector<int> pref(n - 1), suff(n - 1);
        pref[0] = lcp[0];
        for (int i = 1; i < n - 1; i++)
            pref[i] = max(pref[i - 1], lcp[i]);

        // Step 3: suffix max
        suff[n - 2] = lcp[n - 2];
        for (int i = n - 3; i >= 0; i--)
            suff[i] = max(suff[i + 1], lcp[i]);

        // Step 4: process each removal
        for (int i = 0; i < n; i++) {
            int best = 0;

            // left side max
            if (i - 2 >= 0)
                best = max(best, pref[i - 2]);

            // right side max
            if (i + 1 <= n - 2)
                best = max(best, suff[i + 1]);

            // new merged pair
            if (i - 1 >= 0 && i + 1 < n)
                best = max(best, getLCP(words[i - 1], words[i + 1]));

            ans[i] = best;
        }

        return ans;
    }
};