class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int mx=0;
        vector<int>gcds(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            gcds[i]=__gcd(nums[i],mx);
        }
        sort(gcds.begin(),gcds.end());
        int l=0,r=n-1;
        long long sum=0;
        while(l<r){
            sum+=__gcd(gcds[l],gcds[r]);
            l++;
            r--;
        }
        return sum;
    }
};