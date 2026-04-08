class Solution {
public:
typedef long long ll;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod=1e9+7;
        int n=nums.size();
        for(auto& q:queries){
            ll l=q[0];
            ll r=q[1];
            ll k=q[2];
            ll v=q[3];
            while(l<=r){
                nums[l]=(nums[l]*v)%mod;
                l+=k;
            }
        }
        int ans=0;
        for(int x:nums){
            ans^=x;
        }
        return ans;
    }
};