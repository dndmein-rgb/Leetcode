class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=nums[i-1];
            left[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            right[i]=sum;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(right[i+1]-left[i]);
        }
        return ans;
    }
};