class Solution {
public:
int n;
vector<int>cnt;
int dp[1001][1501][2];
int solve(int i,vector<vector<int>>& items, int budget,int taken){
    if(i==n)return 0;
    if(dp[i][budget][taken]!=-1)return dp[i][budget][taken];
    int ans=solve(i+1,items,budget,0);
    int price=items[i][1];
    if(budget >=price){
        if(taken){
            ans=max(ans,1+solve(i,items,budget - price,1));
        }
        else {
            ans=max(ans,1+cnt[i]+solve(i,items,budget - price,1));
        }
    }
    return dp[i][budget][taken]=ans;


}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        cnt.assign(n,0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0){
                    cnt[i]++;
                }
            }
        }
        return solve(0,items,budget,0);
    }
};