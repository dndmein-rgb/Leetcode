class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> v(n);
        
        for (int i = 0; i < n; i++)
            v[i] = abs((long long)nums[i]);
        
        sort(v.begin(), v.end());
        
        long long ans = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            while (j < n && v[j] <= 2 * v[i])
                j++;
            
            ans += (j - i - 1);
        }
        
        return ans;
    }
};