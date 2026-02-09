class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        deque<int> maxDq, minDq;
        long long ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[r])
                maxDq.pop_back();
            maxDq.push_back(r);

            while (!minDq.empty() && nums[minDq.back()] >= nums[r])
                minDq.pop_back();
            minDq.push_back(r);

            while (!maxDq.empty() && !minDq.empty() &&
                   (long long)(nums[maxDq.front()] - nums[minDq.front()]) *
                           (r - l + 1) >
                       k) {
                if (maxDq.front() == l)
                    maxDq.pop_front();
                if (minDq.front() == l)
                    minDq.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    };