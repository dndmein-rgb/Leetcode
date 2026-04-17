class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int k = -1; // all bits set initially

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (k == -1) k = nums[i];
                else k &= nums[i];
            }
        }

        // already sorted case
        if (k == -1) return 0;

        return k;
    }
};