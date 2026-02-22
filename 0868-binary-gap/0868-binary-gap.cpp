class Solution {
public:
    int binaryGap(int n) {
       int prev=-1,curr=0,maxD=0;
       while(n) {
        if(n&1){
            maxD=(prev!=-1)?max(maxD,curr-prev) :maxD;
            prev=curr;
        }
        curr++;
        n>>=1;
       }
       return maxD;
    }
};