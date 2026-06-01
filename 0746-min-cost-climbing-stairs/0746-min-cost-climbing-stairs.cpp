class Solution {
public:
int t[1001];
int n;
int f(int i,vector<int>& cost){
    if(i==n-1){
        return cost[i];
    }
    if(i>=n)return 0;
    if(t[i]!=-1)return t[i];
    int minCost=cost[i]+min(f(i+1,cost),f(i+2,cost));

    return t[i]= minCost;
}
    int minCostClimbingStairs(vector<int>& cost) {
      n=cost.size()  ;
      memset(t,-1,sizeof(t));
      return min(f(0,cost),f(1,cost));
    }
};