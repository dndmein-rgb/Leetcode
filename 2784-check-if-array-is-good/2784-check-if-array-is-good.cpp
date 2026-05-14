class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return false;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(int i=1;i<n;i++){
            if(i==n-1 && mp[i]!=2){
                return false;
                }
            else if(i<n-1 && mp[i]!=1){
                return false;
                }
        }
        return true;
    }
};