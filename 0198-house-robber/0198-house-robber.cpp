class Solution {
public:
    int t[101];
    int n;
    int f(int i, vector<int>& nums) {

        if (i >= n)
            return 0;

        if (t[i] != -1)
            return t[i];

        int take = nums[i] + f(i + 2, nums);
        int notTake = f(i + 1, nums);
        return t[i] =max(take, notTake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return f(0, nums);
    }
};