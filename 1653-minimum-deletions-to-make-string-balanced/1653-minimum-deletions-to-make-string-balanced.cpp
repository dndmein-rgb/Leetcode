class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> prefB(n+1, 0);
        vector<int> suffA(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'b') {
                prefB[i] = prefB[i - 1] + 1;
            } else
                prefB[i] = prefB[i - 1];
        }
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i+1]=='a')suffA[i]=suffA[i+1]+1;
        else suffA[i]=suffA[i+1];
    }
    int lastIdx=0;
    int ans = n;
    for (int i = 0; i <= n; i++)
        ans = min(ans, prefB[i] + suffA[i]);

    return ans;
    }
};