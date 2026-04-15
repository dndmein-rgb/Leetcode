class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        vector<int> indices;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                indices.push_back(i);
            }
        }

        if (indices.empty()) return -1;

        int minD = INT_MAX;

        for (int i : indices) {
            int diff = abs(startIndex - i);
            minD = min(minD, min(diff, n - diff));
        }

        return minD;
    }
};