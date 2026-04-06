class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int maxD = 0;
        unordered_set<string> st;
        for (auto& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }
        pair<int, int> dir = {0, 1};
        for (int k : commands) {
            if (k == -2) {
                dir = {-dir.second, dir.first};
            } else if (k == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int i = 0; i < k; i++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    string nextKey = to_string(newX) + "_" + to_string(newY);
                    if (st.find(nextKey) != st.end())
                        break;
                    x = newX;
                    y = newY;
                }
            }
            maxD = max(maxD, x * x + y * y);
        }
        return maxD;
    }
};