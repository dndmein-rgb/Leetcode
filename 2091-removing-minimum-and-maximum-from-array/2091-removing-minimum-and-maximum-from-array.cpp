class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        int removeLeft = maxIdx + 1;
        int removeRight = n - minIdx;
        int removeBoth = (minIdx + 1) + (n - maxIdx);

        return min({removeLeft, removeRight, removeBoth});
    }
};