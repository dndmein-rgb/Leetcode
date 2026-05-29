class Solution {
public:
int digitSum(int x){
    int sum=0;
    while(x){
        int digit=x%10;
        sum+=digit;
        x/=10;
    }
    return sum;
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