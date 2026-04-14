class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1=0,max2=0;
        for(int num:nums){
            if(abs(num)>max1){
                max2=max1;
                max1=abs(num);
            }else if(abs(num)>max2){
                max2=abs(num);
            }
        }
        return max1*max2*100000;
    }
};