class Solution {
public:
    void solve(int n, int &count, string &curr, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            curr.push_back(ch);
            solve(n, count, curr, k, result);
            if (!result.empty())
                return;
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        solve(n, count, curr, k, result);

        return result;
    }
};