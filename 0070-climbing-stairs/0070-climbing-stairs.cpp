class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)return n;
        int a=1,b=2,c=3;
        for(int i=3;i<=n;i++){
            c=a+b;
            int temp_b=b;
            b=c;
            a=temp_b;
        }
        return c;
    }
};