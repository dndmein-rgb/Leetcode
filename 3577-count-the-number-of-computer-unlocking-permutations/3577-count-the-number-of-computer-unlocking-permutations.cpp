class Solution {
public:
    int mod = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        int val = complexity[0];
        int n = complexity.size();
        for(int i=1; i<n; i++) {
            if(complexity[i] <= val) return 0;
        }

        int ans = 1;
        for(int i=1; i<=n-1; i++) {
            ans = (ans*1LL*i)%mod;
        }

        return ans;
    }
};