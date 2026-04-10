class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>mp,f1;
        for(int num:nums1){
            mp[num]++;
            f1[num]++;
        }
        for(int num:nums2){
            mp[num]++;
        }
        for(auto&[key,val]:mp){
            if(val%2!=0)return -1;
        }
         int moves = 0;

        for(auto&[val,cnt]:f1){
            int need=mp[val]/2;
            if(cnt>need){
                moves+=(cnt-need);
            }
        }
        return moves;
    }
};