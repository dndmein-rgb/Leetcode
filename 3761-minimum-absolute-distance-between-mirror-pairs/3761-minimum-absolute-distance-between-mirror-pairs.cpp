class Solution {
public:
int rev(int n){
    int num=0;
    while(n){
        int digit=n%10;
        n/=10;
        num=num*10+digit;
    }
    return num;
}
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int minD = 1e9;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                minD = min(minD, abs(i - mp[nums[i]]));
            }
            mp[rev(nums[i])]=i;
        }
        return minD == 1e9 ? -1 : minD;
    }
};