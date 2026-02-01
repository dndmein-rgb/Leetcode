class Solution {
public:
    int lis(vector<int>&arr){
        if(arr.empty())return 0;
        vector<int>tails;
        for(int x:arr){
            auto it=lower_bound(tails.begin(),tails.end(),x);
            if(it==tails.end())tails.push_back(x);
            else {
                *it=x;
            }
          
        }
          return tails.size();
    }
    int longestSubsequence(vector<int>& nums) {
       int maxLen=0;
        for(int i=0;i<32;i++){
             vector<int>filtered;
            for(int num:nums){
                if((num>>i)&1)filtered.push_back(num);
            }
            maxLen=max(maxLen,lis(filtered));
        }
        return maxLen;
    }
};