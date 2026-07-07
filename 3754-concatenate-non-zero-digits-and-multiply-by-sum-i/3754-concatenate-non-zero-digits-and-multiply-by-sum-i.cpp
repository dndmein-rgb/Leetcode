class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        long long mul=1;
        long long sum=0;
        while(n){
            int digit=n%10;
            sum+=digit;
            num+=digit*mul;
            if(digit!=0)mul*=10;
            
            n/=10;
        }
        return num*sum;

    }
};