class Solution {
public:
    int concatenatedBinary(int n) {
        long num=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            int digits=log2(i)+1;
            num=(((num<<digits)%mod)+i)%mod;
        }
        return num;
    }
};