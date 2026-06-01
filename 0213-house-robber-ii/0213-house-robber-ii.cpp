class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n == 1)
            return nums[0];
        vector<int> t(n + 1);
        t[0] = 0, t[1] = nums[0];
        int result1 = 0, result2 = 0;

        //first house start
        for (int i = 2; i <= n - 1; i++) {
            int steal = t[i - 2] + nums[i - 1];
            int notSteal = t[i - 1];
            t[i] = max(steal, notSteal);
        }
        result1 = t[n - 1];


        //2nd house start
        t.clear();
        t[0] = 0;
        t[1] = 0;
        for (int i = 2; i <= n; i++) {
            int steal = t[i - 2] + nums[i - 1];
            int notSteal = t[i - 1];
            t[i] = max(steal, notSteal);
        }
        result2 = t[n];

        return max(result1, result2);
    }
};