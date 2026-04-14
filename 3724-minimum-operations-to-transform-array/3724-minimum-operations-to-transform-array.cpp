class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        long long base=0;
        for(int i=0;i<n;i++){
            base+=(abs(nums1[i]-nums2[i]));
        }
        long long target=nums2[n];
        long long extra=LLONG_MAX;
        for(int i=0;i<n;i++){
            int a=nums1[i],b=nums2[i];
            if(min(a,b)<=target && max(a,b)>=target){
                extra=0 ;
                 break;
            }
            extra=min({extra,(long long)abs(a-target),(long long)abs(b-target)});
        }
        return base+extra+1;
    }
};