class Solution {
public:
typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<ll>profit(n);
        ll actualProfit=0;
        for(int i=0;i<n;i++){
            profit[i]=prices[i]*strategy[i];
            actualProfit+=profit[i];
        }
        ll modifiedWindowProfit=0;
        ll originalWindowProfit=0;
        ll gain=0;
        int i=0,j=0;
        while(j<n){
            originalWindowProfit+=profit[j];
            if(j-i+1>k/2){
                modifiedWindowProfit+=prices[j];
            }
            if(j-i+1>k){
                modifiedWindowProfit-=prices[i+k/2] ;
                originalWindowProfit-=profit[i];
                i++;
            }
            if(j-i+1==k){
                gain=max(gain,modifiedWindowProfit-originalWindowProfit);
            }
            j++;
        }
        return actualProfit+gain;
    }
};