class Solution {
public:
    int start = 0, maxLen = 1,  n;
    void expand(int i, int j, string& s) {
        while (i >= 0 && j < n && s[i] == s[j]) {
           
        
        int len = j - i + 1;
        if (len > maxLen) {
            maxLen = len;
            start = i;
        }
         i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return s.substr(start,maxLen);

    }
};