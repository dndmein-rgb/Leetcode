class Solution {
public:
const int mod=1e9+7;
long long factorial(int n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++)
        ans =( ans*i)%mod;
    return ans;
}
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        vector<bool>decrypt(n,false);
        int smallest=complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i]>smallest)decrypt[i]=true;
        }
        for(int i=1;i<n;i++){
            if(decrypt[i]==false)return 0;
        }
        return factorial(n-1)%mod;
    }
};