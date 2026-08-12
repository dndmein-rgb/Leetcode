class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int i=0,j=0;
        int maxLen=0;
        while(j<n){
            freq[nums[j]]++;
    while(freq[nums[j]]>k){
        int left=nums[i];
        freq[left]--;
        i++;
    }
    maxLen=max(maxLen,j-i+1);
    j++;
        }
        return maxLen;
    }
};