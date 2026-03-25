class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0,start=1;
        int commas=0;
        while(start<=n){
            long long end=start*1000-1;
            long long count=max(0LL,min(n,end)-start+1);
            ans+=count*commas;
            start*=1000;
            commas++;
        }
        return ans;
    }
};