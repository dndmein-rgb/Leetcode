class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>mp;
        int balance=0,Xor=0;
        mp[{0,0}]=-1;
        int len=0;
        for(int i=0;i<nums.size();i++){
            Xor^=nums[i];
            balance+=(nums[i]%2==0?-1:1);
            if(mp.count({Xor,balance})){
                len=max(len,i-mp[{Xor,balance}]);
            }
            else {
                mp[{Xor,balance}]=i;

            }
        }
        return len;
    }
};