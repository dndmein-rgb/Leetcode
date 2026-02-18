class Solution {
public:

    int largestPrime(int n) {
        if(n==1)return false;
        //  if(n>=398771)return 398771;
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i ;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        int sum=0,ans=0;
       for(int i=2;i<=n;i++){
        if(isPrime[i]){
            sum+=i;
            if(sum>n)break;
            if(isPrime[sum])ans=sum;
        }
       }
        return ans;
    }
};