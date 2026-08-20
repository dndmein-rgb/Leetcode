class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans1,ans2;
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(ans1.back()>ans2.back())ans1.push_back(nums[i]);
            else ans2.push_back(nums[i]);
        }
        vector<int> result=ans1;
result.insert(result.end(),ans2.begin(),ans2.end());
        return result;
    }
};