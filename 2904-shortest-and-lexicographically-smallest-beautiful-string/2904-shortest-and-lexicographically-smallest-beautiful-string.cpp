class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        vector<int> pref(n + 1);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                count++;

            pref[i + 1] = count;
        }

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (pref[j + 1] - pref[i] == k) {
                    string sub = s.substr(i, j - i + 1);
                    ans.push_back(sub);
                }
            }
        }

        if (ans.empty())
            return "";

        sort(ans.begin(), ans.end(), [](const string& a, const string& b) {
            if (a.length() != b.length())
                return a.length() < b.length();

            return a < b;
        });

        return ans[0];
    }
};