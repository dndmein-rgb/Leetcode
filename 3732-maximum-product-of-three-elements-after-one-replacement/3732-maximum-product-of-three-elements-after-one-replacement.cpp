class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long max1=0,max2=0;
        for(int i=0;i<n;i++){
            if(abs(nums[i])>max1){
                max2=max1;
                max1=abs(nums[i]);  
            }else if(abs(nums[i])>max2){
                max2=abs(nums[i]);
            }
        }
        long long max3=max1*max2;
        return max3*100000;
    }
};