class Solution {
public:
int rev(int n){
    int  num=0;
    while(n){
        int digit=n%10;
        num=num*10+digit;
        n/=10;
    }
    return num;
}
    int mirrorDistance(int n) {
        int revNum=rev(n);
        return abs(revNum-n);
    }
};