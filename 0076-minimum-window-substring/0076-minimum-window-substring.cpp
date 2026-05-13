class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        vector<int> need(256, 0), window(256, 0);
        int i = 0, j = 0;
        int required = 0, formed = 0;
        int minLen = 1e9;
        int start = 0;
        for (char c : t) {
            if (need[c] == 0)
                required++;
            need[c]++;
        }
        while (j < s.size()) {
            char c = s[j];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c])
                formed++;
            while (i <= j && formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                char left = s[i];
                window[left]--;
                if (need[left] > 0 && need[left] > window[left]) {
                    formed--;
                }
                i++;
            }
            j++;
        }
        return minLen == 1e9 ? "" : s.substr(start, minLen);
    }
};