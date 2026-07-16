class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<int>maxNum(n);
        maxNum[0]=nums[0];
        for(int i=1;i<n;i++){
            maxNum[i]=max(nums[i],maxNum[i-1]);
        }
        vector<int>gcds(n);
        for(int i=0;i<n;i++){
            gcds[i]=__gcd(nums[i],maxNum[i]);
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