class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=1e9;
        for(auto&[key,vec]:mp){
            int m=vec.size();
            if(m>=3){
                
                for(int i=0;i+2<m;i++){
                    int distance=2*(vec[i+2]-vec[i]);
                    ans=min(ans,distance);
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};