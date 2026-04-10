class Solution {
public:
int mod=1e9+7;
typedef long long ll;
int modpow(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b%2)ans=(ans%mod*a%mod)%mod;
        b/=2;
        a=((a%mod)*(a%mod))%mod;
    }
    return ans;
}
    int countVisiblePeople(int n, int pos, int k) {
        vector<ll>fact(n+1,1);
        for(int i=1;i<n;i++){
            fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
        }
        ll ans=1;
        ans=(ans*(fact[n-1]%mod)*modpow(fact[k],mod-2)%mod)%mod;
        ans=(ans*modpow(fact[n-1-k],mod-2)%mod)%mod;
        ans=(ans%mod*2)%mod;
        return ans;
    }
    
};