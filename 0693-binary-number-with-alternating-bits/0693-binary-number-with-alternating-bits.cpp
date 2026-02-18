class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool one=n&1;
        n>>=1;
        while(n){
            bool test=n&1;
            if(one==test)return false;
            n>>=1;
            one=!one;
        }
        return true;
    }
};