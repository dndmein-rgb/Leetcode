class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=nums1[0];
        bool oddPresent=false;
        for(int x:nums1){
            if(x<mn)mn=x;
            if(x%2!=0)oddPresent=true;
        }
        if(mn %2==0 && oddPresent)return false;
        return true;
    }
};