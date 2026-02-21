class Solution {
public:
bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
int counter(int n){
    int count=0;
    while(n){
        count+=n&1;
        n>>=1;
    }
    return count;
}
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int x=counter(i);
            if(isPrime(x)){
                count++;
            }
        }
        return count;
    }
};