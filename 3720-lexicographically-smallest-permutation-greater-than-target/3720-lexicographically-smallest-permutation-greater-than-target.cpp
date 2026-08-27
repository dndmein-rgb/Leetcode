class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string quinorath = s;
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        string res = "";
        if (backtrack(0, n, target, count, res, false))
            return res;
        return "";
    }

private:
    bool backtrack(int pos, int n, string &target, vector<int> &count, string &res, bool greater) {
        if (pos == n) return greater;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) continue;
            char c = 'a' + i;
            if (!greater && c < target[pos]) continue;
            count[i]--;
            res.push_back(c);
            bool nextGreater = greater || (c > target[pos]);
            if (backtrack(pos + 1, n, target, count, res, nextGreater))
                return true;
            res.pop_back();
            count[i]++;
        }
        return false;
    }
};
