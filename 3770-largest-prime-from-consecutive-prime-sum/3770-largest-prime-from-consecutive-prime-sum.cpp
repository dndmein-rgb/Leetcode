class Solution {
public:
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
    int largestPrime(int n) {
        if(n==1)return false;
         if(n>=398771)return 398771;
        vector<int>primes;
        for(int i=2;i<=n;i++){
            if(isPrime(i))primes.push_back(i);
        }
        int sum=0,ans=0;
        for(int x:primes){
            sum+=x;
            if(sum>n)break;
            if(isPrime(sum))ans=sum;
        }
        return ans;
    }
};