class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int num : arr1) {
            while (num) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int longest = 0;

        for (int num : arr2) {
            while (num) {
                if (prefixes.count(num)) {
                    longest = max(longest, num);
                }
                num /= 10;
            }
        }
        return longest == 0 ? 0 : to_string(longest).size();
        
    }
};