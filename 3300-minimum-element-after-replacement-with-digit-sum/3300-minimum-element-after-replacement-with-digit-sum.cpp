class Solution {
public:
int digitSum(int n){
   return (n/10000)+(n%10000/1000)+(n%1000/100)+(n%100/10)+n%10;
}
    int minElement(vector<int>& nums) {
        int mini=1e9;
        for(int num:nums){
            int sum=digitSum(num);
            mini=min(mini,sum);
        }
        return mini;
    }
};