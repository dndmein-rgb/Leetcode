class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "", ans1 = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if(ans1.size() > 0){
                if (ans.size() > 0) 
                    ans += " ";

                    reverse(ans1.begin(), ans1.end());
                    ans += ans1;
                    ans1 = "";
                }

            } else
                ans1 += s[i];
        }

        if (ans1.size() > 0) {
            if (!ans.empty())
                ans += " ";
            reverse(ans1.begin(), ans1.end());
            ans += ans1;
        }

        return ans;
    }
};