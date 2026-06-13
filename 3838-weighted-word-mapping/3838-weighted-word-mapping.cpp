class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (string& s : words) {
            int sum = 0;
            for (char c : s) {
                sum += weights[c - 'a'];
            }
            sum %= 26;
            sum = 25 - sum;
            ans.push_back('a' + sum);
        }
        return ans;
    }
};