class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)return nums;
        vector<int>pos_indices,positives;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                positives.push_back(nums[i]);
                pos_indices.push_back(i);
            }
        }
        int count=positives.size();
        if(count==0)return nums;
        k = k % count;
        vector<int>ans=nums;
        for(int i=0;i<count;i++){
            ans[pos_indices[i]]=positives[(i+k)%count];
        }
        return ans;
    }
};