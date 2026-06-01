class Solution {
public:
int t[46];
int climb(int i,int n){
    if(i==n)return 1;
    if(i>n)return 0;
    if(t[i]!=-1)return t[i];

    return t[i]=climb(i+1,n)+climb(i+2,n);
}
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return climb(0,n);
    }
};