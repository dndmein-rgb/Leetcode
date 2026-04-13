class Solution {
public:
int rev(int n){
    string s=to_string(n);
    reverse(s.begin(),s.end());
    n=stoi(s);
    return n;
}
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int minD=INT_MAX;
        for(int i=0;i<n;i++){
            if(!mp.empty() && mp.count(nums[i])){
                minD=min(minD,abs(i-mp[nums[i]]));
            }
            mp[rev(nums[i])]=i;
        }
    return minD==INT_MAX?-1:minD;
    }
};