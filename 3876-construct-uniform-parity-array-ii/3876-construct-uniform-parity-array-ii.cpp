class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        if (minOdd == INT_MAX)
            return true;

        if (minEven == INT_MAX)
            return true;

        return minOdd < minEven;
    }
};