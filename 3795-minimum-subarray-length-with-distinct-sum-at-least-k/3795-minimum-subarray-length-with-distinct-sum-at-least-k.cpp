class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int minLen=n+1;
        while(j<n){
            if(!mp.count(nums[j])){
                sum+=nums[j];
            }
            mp[nums[j]]++;
             if(sum>=k)minLen=min(minLen,j-i+1);
            while(sum>=k){
                
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                    sum-=nums[i];
                }
                i++;
                if(sum>=k)minLen=min(minLen,j-i+1);
            }
           
            j++;
        }
        return minLen==n+1?-1:minLen;
    }
};