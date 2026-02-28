class Solution {
public:
const int mod=1e9+7;
    string binaryRep(int n){
        string s;
        while(n){
            int digit=n&1;
            s.push_back(digit+'0');
            n>>=1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int binaryToDecimal(string s){
        int result=0;
        for(char c:s){
            result=(result*2+(c-'0'))%mod;
        }
        return result;
    }
    int concatenatedBinary(int n) {
        string s;
        for(int i=1;i<=n;i++){
            s+=binaryRep(i);
        }
        int size=s.length();
        int j=size-1;
        int num=binaryToDecimal(s);
        return num;
        
    }
};