class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long >ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            long long val=nums[i];
            while(ans.size()>0 && ans.back()==val){
                ans.pop_back();
                val=val*2;
            }
            ans.push_back(val);
        }
        return ans;

    }
};