class Solution {
public:
   int t[101];
    int f(int i, vector<int>& nums,int n) {

        if (i > n)
            return 0;

        if (t[i] != -1)
            return t[i];

        int take = nums[i] + f(i + 2, nums,n);
        int notTake = f(i + 1, nums,n);
        return t[i] =max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        memset(t,-1,sizeof(t));
        int try1=f(0,nums,n-2);
        memset(t,-1,sizeof(t));
        int try2=f(1,nums,n-1);

        return max(try1,try2);
    }
};