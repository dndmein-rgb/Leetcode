class Solution {
public:
int digitSum(int n){
    int sum=0;
    while(n){
        int digit=n%10;
        sum+=digit;
        n/=10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
       int n=nums.size() ;
       
       for(int i=0;i<n;i++){
       int dSum=digitSum(nums[i]);
       if(dSum==i)return i;
       }
       return -1;
    }
};