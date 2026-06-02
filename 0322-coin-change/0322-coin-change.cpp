class Solution {
public:
int t[13][10001];
int n;
int solve(int i,vector<int>&coins,int amount){
   if(amount==0)return 0;
   if(t[i][amount]!=-1)return t[i][amount];
   if(i>=n)return 1e9;

   int take=1e9;
   if(amount>=coins[i]){
    take=1+solve(i,coins,amount-coins[i]);
   }
   int notTake=solve(i+1,coins,amount);

   return t[i][amount]=min(take,notTake);
}
    int coinChange(vector<int>& coins, int amount) {
         n=coins.size();
         memset(t,-1,sizeof(t));
         int ans=solve(0,coins,amount);
         return ans>=1e9 ?-1:ans;
    }
};