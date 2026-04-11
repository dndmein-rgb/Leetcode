class Solution {
public:
    bool isValid(vector<int>& nums, long long k) {
        long long ops = 0;
        long long limit = k * k;

        for (int num : nums) {
            ops += (num + k - 1) / k;  // ceil division

            if (ops > limit) return false; // early exit
        }
        return ops <= limit;
    }

    int minimumK(vector<int>& nums) {
        long long low = 1, high = 100000;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isValid(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};