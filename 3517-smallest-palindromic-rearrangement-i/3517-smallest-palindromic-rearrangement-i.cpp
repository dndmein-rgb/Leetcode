class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans;
        char middle;
        bool found = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                found = true;
                middle = i + 'a';
            }
            while (freq[i] / 2) {
                ans.push_back(i + 'a');
                freq[i] -= 2;
            }
        }
        string reversed = ans;
        reverse(reversed.begin(), reversed.end());
        if (found) {
            return ans + middle + reversed;
        }
        return ans + reversed;
    }
};