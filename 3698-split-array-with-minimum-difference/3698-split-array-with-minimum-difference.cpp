class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<bool>inc(n,false),dec(n,false);
        inc[0]=true;
        for(int i=1;i<n;i++){
            inc[i]=inc[i-1] && (nums[i]>nums[i-1]);
        }
        dec[n-1]=true;
        for(int i=n-2;i>=0;i--){
            dec[i]=dec[i+1] && (nums[i]>nums[i+1]);
        }
        vector<int>pref(n,0);
        pref[0]=nums[0];
        long long total=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
            total+=nums[i];
        }
        long long minD=LLONG_MAX;
        bool found=false;
        for(int i=0;i<n;i++){
            if(inc[i] && dec[i+1]){
                long long left=pref[i];
                long long right=total-left;
                minD=min(minD,llabs(left-right));
                found=true;
            }
        }
        return found?minD:-1;

    }
};