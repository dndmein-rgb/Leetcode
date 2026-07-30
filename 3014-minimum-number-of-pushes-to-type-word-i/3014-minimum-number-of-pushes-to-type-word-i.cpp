class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8)return n;
        int mul=1;
        int ans=0;
    while(n>0){
        if(n<8){
            ans+=n*mul;
            }
        else ans+=8*mul;
        mul++;
        n-=8;
    }
    return ans;
    }
};